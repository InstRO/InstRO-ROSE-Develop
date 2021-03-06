/* Reads a binary file, disassembles it, and spits out a control flow graph. */
#include "rose.h"
#include "BinaryControlFlow.h"

using namespace rose::BinaryAnalysis;

#include <boost/graph/graphviz.hpp>

/* Label the graphviz vertices with basic block addresses rather than vertex numbers. */
template<class ControlFlowGraph>
struct GraphvizVertexWriter {
    const ControlFlowGraph &cfg;
    GraphvizVertexWriter(ControlFlowGraph &cfg): cfg(cfg) {}
    void operator()(std::ostream &output,
                    const typename boost::graph_traits<ControlFlowGraph>::vertex_descriptor &v) {
        if (SgAsmBlock *block = isSgAsmBlock(get_ast_node(cfg, v))) {
            output <<"[ label=\"" <<StringUtility::addrToString(block->get_address()) <<"\" ]";
        } else if (SgAsmInstruction *insn = isSgAsmInstruction(get_ast_node(cfg, v))) {
            output <<"[ label=\"" <<unparseInstructionWithAddress(insn) <<"\" ]";
        }
    }
};

/* Filter that accepts only function call edges.
 * FIXME: This treats intra-function edges going to the entry block as if they were recursive calls */
struct OnlyCallEdges: public ControlFlow::EdgeFilter {
    bool operator()(ControlFlow *analyzer, SgAsmNode *src, SgAsmNode *dst) {
        SgAsmBlock *dst_block = SageInterface::getEnclosingNode<SgAsmBlock>(dst, true);
        SgAsmFunction *dst_func = dst_block->get_enclosing_function();
        return dst_func && dst_block == dst_func->get_entry_block();
    }
};

/* Filter that rejects basic block that are uncategorized.  I.e., those blocks that were disassemble but not ultimately
 * linked into the list of known functions.  We excluded these because their control flow information is often nonsensical. */
struct ExcludeLeftovers: public ControlFlow::VertexFilter {
    bool operator()(ControlFlow *analyzer, SgAsmNode *node) {
        SgAsmFunction *func = SageInterface::getEnclosingNode<SgAsmFunction>(node, true);
        return func && 0==(func->get_reason() & SgAsmFunction::FUNC_LEFTOVERS);
    }
};

int
main(int argc, char *argv[])
{
    /* Algorithm is first argument. */
    assert(argc>1);
    std::string algorithm = argv[1];
    memmove(argv+1, argv+2, argc-1); /* also copy null ptr */
    --argc;

    /* Parse the binary file */
    SgProject *project = frontend(argc, argv);
    std::vector<SgAsmInterpretation*> interps = SageInterface::querySubTree<SgAsmInterpretation>(project);
    if (interps.empty()) {
        fprintf(stderr, "no binary interpretations found\n");
        exit(1);
    }

    ExcludeLeftovers exclude_leftovers;

    /* Calculate plain old CFG. */
    if (algorithm=="A") {
        typedef ControlFlow::Graph CFG;
        ControlFlow cfg_analyzer;
        cfg_analyzer.set_vertex_filter(&exclude_leftovers);
        CFG cfg = cfg_analyzer.build_block_cfg_from_ast<CFG>(interps.back());
        boost::write_graphviz(std::cout, cfg, GraphvizVertexWriter<CFG>(cfg));
    }

    /* Calculate a CFG with only function call edges.  Note that this is not quite the same as
     * FunctionCall::Graph. */
    if (algorithm=="B") {
        typedef ControlFlow::Graph CFG;
        ControlFlow cfg_analyzer;
        cfg_analyzer.set_vertex_filter(&exclude_leftovers);
        CFG cfg = cfg_analyzer.build_cg_from_ast<CFG>(interps.back());
        boost::write_graphviz(std::cout, cfg, GraphvizVertexWriter<CFG>(cfg));
    }

    /* Build a pseudo call-graph by first building a CFG and then copying it to filter out non-call edges.  The result
     * should be the same as for algorithm B, assuming our edge filter is semantically equivalent. */
    if (algorithm=="C") {
        typedef ControlFlow::Graph CFG;
        ControlFlow cfg_analyzer;
        cfg_analyzer.set_vertex_filter(&exclude_leftovers);
        CFG cfg = cfg_analyzer.build_block_cfg_from_ast<CFG>(interps.back());
        OnlyCallEdges edge_filter;
        cfg_analyzer.set_edge_filter(&edge_filter);
        ControlFlow::Graph cg = cfg_analyzer.copy(cfg);
        boost::write_graphviz(std::cout, cg, GraphvizVertexWriter<CFG>(cg));
    }

    /* Build a pseudo call-graph by defining an edge filter before building a regular call graph.  The result should be the
     * same as for algorithm C since both use the same filter. */
    if (algorithm=="D") {
        typedef ControlFlow::Graph CFG;
        ControlFlow cfg_analyzer;
        cfg_analyzer.set_vertex_filter(&exclude_leftovers);
        OnlyCallEdges edge_filter;
        cfg_analyzer.set_edge_filter(&edge_filter);
        CFG cfg = cfg_analyzer.build_block_cfg_from_ast<CFG>(interps.back());
        boost::write_graphviz(std::cout, cfg, GraphvizVertexWriter<CFG>(cfg));
    }

    /* Build an instruction-based control flow graph. */
    if (algorithm=="E") {
        typedef ControlFlow::InsnGraph CFG;
        ControlFlow cfg_analyzer;
        cfg_analyzer.set_vertex_filter(&exclude_leftovers);
        CFG cfg = cfg_analyzer.build_insn_cfg_from_ast<CFG>(interps.back());
        boost::write_graphviz(std::cout, cfg, GraphvizVertexWriter<CFG>(cfg));
    }
    
    return 0;
};

        
        
    
