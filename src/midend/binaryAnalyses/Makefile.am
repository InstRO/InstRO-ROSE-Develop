include $(top_srcdir)/config/Makefile.for.ROSE.includes.and.libs

INCLUDES = -Winvalid-pch $(ROSE_INCLUDES) -I$(srcdir)/graph -I$(srcdir)/libraryIdentification 

noinst_LTLIBRARIES = libbinaryMidend.la
libbinaryMidend_la_DEPENDENCIES =

if ROSE_BUILD_BINARY_ANALYSIS_SUPPORT
libbinaryMidend_la_SOURCES =					\
    AbstractLocation.C						\
    binary_analysis.C						\
    RoseBin_CompareAnalysis.cpp RoseBin_ControlFlowAnalysis.cpp	\
    RoseBin_printInstructions.cpp RoseBin_DataFlowAnalysis.cpp	\
    RoseBin_CallGraphAnalysis.cpp RoseBin_FlowAnalysis.cpp	\
    dataflowanalyses/RoseBin_DefUseAnalysis.cpp			\
    dataflowanalyses/RoseBin_VariableAnalysis.cpp		\
    dataflowanalyses/InterruptAnalysis.cpp			\
    dataflowanalyses/RoseBin_Emulate.cpp			\
    dataflowanalyses/RoseBin_DataFlowAbstract.cpp		\
    instructionSemantics/BaseSemantics2.C			\
    instructionSemantics/ConcreteSemantics2.C			\
    instructionSemantics/DataFlowSemantics2.C			\
    instructionSemantics/DispatcherM68k.C			\
    instructionSemantics/DispatcherPowerpc.C			\
    instructionSemantics/DispatcherX86.C			\
    instructionSemantics/NullSemantics2.C			\
    instructionSemantics/MultiSemantics2.C			\
    instructionSemantics/PartialSymbolicSemantics2.C		\
    instructionSemantics/findConstants.C			\
    instructionSemantics/FindRegisterDefs.C			\
    instructionSemantics/InsnSemanticsExpr.C			\
    instructionSemantics/IntervalSemantics.C			\
    instructionSemantics/IntervalSemantics2.C			\
    instructionSemantics/LlvmSemantics2.C			\
    instructionSemantics/PartialSymbolicSemantics.C		\
    instructionSemantics/TraceSemantics2.C			\
    instructionSemantics/SMTSolver.C				\
    instructionSemantics/StaticSemantics2.C			\
    instructionSemantics/SymbolicMemory2.C			\
    instructionSemantics/SymbolicSemantics.C			\
    instructionSemantics/SymbolicSemantics2.C			\
    instructionSemantics/YicesSolver.C				\
    GraphAlgorithms.C						\
    BinaryControlFlow.C						\
    BinaryDataFlow.C						\
    BinaryDominance.C						\
    BinaryFunctionCall.C					\
    BinaryCallingConvention.C					\
    BinaryMagic.C						\
    BinaryNoOperation.C						\
    BinaryReturnValueUsed.C					\
    BinaryString.C						\
    BinaryTaintedFlow.C						\
    DwarfLineMapper.C
else
libbinaryMidend_la_SOURCES = dummyBinaryMidend.C
endif

if ROSE_USE_SQLITE_DATABASE
libbinaryMidend_la_SOURCES +=					\
    libraryIdentification/libraryIdentification_reader.C	\
    libraryIdentification/libraryIdentification_writer.C	\
    libraryIdentification/functionIdentification.C 
endif

pkginclude_HEADERS =					\
    AbstractLocation.h					\
    binary_analysis.h					\
    GraphAlgorithms.h					\
    RoseBin_CallGraphAnalysis.h				\
    RoseBin_CompareAnalysis.h				\
    RoseBin_ControlFlowAnalysis.h			\
    RoseBin_DataFlowAnalysis.h				\
    RoseBin_FlowAnalysis.h				\
    RoseBin_printInstructions.h				\
    dataflowanalyses/InterruptAnalysis.h		\
    dataflowanalyses/RoseBin_DataFlowAbstract.h		\
    dataflowanalyses/RoseBin_DefUseAnalysis.h		\
    dataflowanalyses/RoseBin_Emulate.h			\
    dataflowanalyses/RoseBin_VariableAnalysis.h		\
    instructionSemantics/ReadWriteRegisterFragment.h	\
    instructionSemantics/findConstants.h		\
    instructionSemantics/FindRegisterDefs.h		\
    instructionSemantics/InsnSemanticsExpr.h		\
    instructionSemantics/BaseSemantics.h		\
    instructionSemantics/BaseSemantics2.h		\
    instructionSemantics/ConcreteSemantics2.h		\
    instructionSemantics/DataFlowSemantics2.h		\
    instructionSemantics/DispatcherM68k.h		\
    instructionSemantics/DispatcherPowerpc.h		\
    instructionSemantics/DispatcherX86.h		\
    instructionSemantics/IntervalSemantics.h		\
    instructionSemantics/IntervalSemantics2.h		\
    instructionSemantics/LlvmSemantics2.h		\
    instructionSemantics/NullSemantics.h		\
    instructionSemantics/NullSemantics2.h		\
    instructionSemantics/MultiSemantics.h		\
    instructionSemantics/MultiSemantics2.h		\
    instructionSemantics/PartialSymbolicSemantics.h	\
    instructionSemantics/PartialSymbolicSemantics2.h	\
    instructionSemantics/SMTSolver.h			\
    instructionSemantics/StaticSemantics2.h		\
    instructionSemantics/SymbolicMemory2.h		\
    instructionSemantics/SymbolicSemantics.h		\
    instructionSemantics/SymbolicSemantics2.h		\
    instructionSemantics/TestSemantics2.h		\
    instructionSemantics/TraceSemantics2.h		\
    instructionSemantics/YicesSolver.h			\
    instructionSemantics/flowEquations.h		\
    instructionSemantics/x86InstructionSemantics.h	\
    libraryIdentification/functionIdentification.h	\
    libraryIdentification/libraryIdentification.h	\
    ether.h						\
    BinaryControlFlow.h					\
    BinaryDataFlow.h					\
    BinaryDominance.h					\
    BinaryFunctionCall.h				\
    BinaryCallingConvention.h				\
    BinaryMagic.h					\
    BinaryNoOperation.h					\
    BinaryPointerDetection.h				\
    BinaryAnalysisUtils.h				\
    BinaryReturnValueUsed.h				\
    BinaryString.h					\
    BinaryTaintedFlow.h					\
    DwarfLineMapper.h


EXTRA_DIST = CMakeLists.txt dummyBinaryMidend.C
