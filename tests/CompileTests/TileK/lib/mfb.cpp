
#include "sage3basic.h"

#include "DLX/TileK/language.hpp"
typedef ::DLX::TileK::language_t Dlang; // Directives Language

#include "DLX/KLT/annotations.hpp"
typedef ::DLX::KLT::Annotation<Dlang> Annotation;

#include "KLT/Language/c-family.hpp"
typedef ::KLT::Language::C Hlang; // Host Language
typedef ::KLT::Language::C Klang; // Kernel Language

#include "MDCG/KLT/runtime.hpp"
typedef ::MDCG::KLT::Runtime<Hlang, Klang> Runtime; // Runtime Description

#include "KLT/Core/data.hpp"
typedef ::KLT::Data<Annotation> Data;

#include "KLT/Core/loop-trees.hpp"
typedef ::KLT::LoopTrees<Annotation> LoopTrees;

#include "KLT/Core/kernel.hpp"
typedef ::KLT::Kernel<Annotation, Runtime> Kernel;

#include "KLT/Core/loop-tiler.hpp"
typedef ::KLT::LoopTiler<Annotation, Runtime> LoopTiler;

#include "KLT/Core/mfb-klt.hpp"

#include "MFB/utils.hpp"

namespace MFB {

template <>
SgBasicBlock * createLocalDeclarations<Annotation, Runtime>(
  Driver<Sage> & driver,
  SgFunctionDefinition * kernel_defn,
  Kernel::local_symbol_maps_t & local_symbol_maps,
  const Kernel::arguments_t & arguments,
  const std::map<LoopTrees::loop_t *, LoopTiler::loop_tiling_t *> & loop_tiling
) {
  std::list<SgVariableSymbol *>::const_iterator it_var_sym;
  std::list<Data *>::const_iterator it_data;

  std::map<SgVariableSymbol *, SgVariableSymbol *>::const_iterator   it_param_to_field;
  std::map<SgVariableSymbol *, SgVariableSymbol *>::const_iterator   it_scalar_to_field;
  std::map<Data *, SgVariableSymbol *>::const_iterator it_data_to_field;

  std::map<LoopTrees::loop_t *, LoopTiler::loop_tiling_t *>::const_iterator it_loop_tiling;
  
  // * Definition *

  SgBasicBlock * kernel_body = kernel_defn->get_body();
  assert(kernel_body != NULL);

  // * Lookup parameter symbols *

  SgVariableSymbol * arg_param_sym = kernel_defn->lookup_variable_symbol("param");
  assert(arg_param_sym != NULL);

  int arg_cnt = 0;
  for (it_var_sym = arguments.parameters.begin(); it_var_sym != arguments.parameters.end(); it_var_sym++) {
    SgVariableSymbol * param_sym = *it_var_sym;
    std::string param_name = param_sym->get_name().getString();
    SgType * param_type = param_sym->get_type();

    driver.useType(param_type, kernel_body);

    SgInitializer * init = SageBuilder::buildAssignInitializer(SageBuilder::buildPntrArrRefExp(SageBuilder::buildVarRefExp(arg_param_sym), SageBuilder::buildIntVal(arg_cnt)));
    SageInterface::prependStatement(SageBuilder::buildVariableDeclaration(param_name, param_type, init, kernel_body), kernel_body);
    SgVariableSymbol * new_sym = kernel_body->lookup_variable_symbol(param_name);
    assert(new_sym != NULL);

    local_symbol_maps.parameters.insert(std::pair<SgVariableSymbol *, SgVariableSymbol *>(param_sym, new_sym));
    arg_cnt++;
  }

  // * Lookup data symbols *

  SgVariableSymbol * arg_data_sym = kernel_defn->lookup_variable_symbol("data");
  assert(arg_data_sym != NULL);

  arg_cnt = 0;
  for (it_data = arguments.datas.begin(); it_data != arguments.datas.end(); it_data++) {
    Data * data = *it_data;
    SgVariableSymbol * data_sym = data->getVariableSymbol();
    std::string data_name = data_sym->get_name().getString();
    SgType * data_type = data->getBaseType();

    driver.useType(data_type, kernel_body);

    SgExpression * init = SageBuilder::buildCastExp(
      SageBuilder::buildPntrArrRefExp(SageBuilder::buildVarRefExp(arg_data_sym), SageBuilder::buildIntVal(arg_cnt)),
      SageBuilder::buildPointerType(data_type)
    );

    if (data->getSections().size() > 0)
      data_type = SageBuilder::buildPointerType(data_type);
    else {
      init = SageBuilder::buildPointerDerefExp(init);
    }

    SageInterface::prependStatement(SageBuilder::buildVariableDeclaration(data_name, data_type, SageBuilder::buildAssignInitializer(init), kernel_body), kernel_body);
    SgVariableSymbol * new_sym = kernel_body->lookup_variable_symbol(data_name);
    assert(new_sym != NULL);

    local_symbol_maps.datas.insert(std::pair<Data *, SgVariableSymbol *>(data, new_sym));
    arg_cnt++;
  }

  // * Lookup scalar symbols *

  SgVariableSymbol * arg_scalar_sym = kernel_defn->lookup_variable_symbol("scalar");
  assert(arg_scalar_sym != NULL);

  arg_cnt = 0;
  for (it_var_sym = arguments.scalars.begin(); it_var_sym != arguments.scalars.end(); it_var_sym++) {
    SgVariableSymbol * scalar_sym = *it_var_sym;
    std::string scalar_name = scalar_sym->get_name().getString();
    SgType * scalar_type = scalar_sym->get_type();

    driver.useType(scalar_type, kernel_body);

    SgExpression * init = SageBuilder::buildPointerDerefExp(SageBuilder::buildCastExp(
                            SageBuilder::buildPntrArrRefExp(SageBuilder::buildVarRefExp(arg_scalar_sym), SageBuilder::buildIntVal(arg_cnt)),
                            SageBuilder::buildPointerType(scalar_type)
                          ));

    SageInterface::prependStatement(SageBuilder::buildVariableDeclaration(scalar_name, scalar_type, SageBuilder::buildAssignInitializer(init), kernel_body), kernel_body);
    SgVariableSymbol * new_sym = kernel_body->lookup_variable_symbol(scalar_name);
    assert(new_sym != NULL);

    local_symbol_maps.scalars.insert(std::pair<SgVariableSymbol *, SgVariableSymbol *>(scalar_sym, new_sym));
    arg_cnt++;
  }

  // * Create iterator *

#ifdef TILEK_THREADS
  SgVariableSymbol * arg_tid_sym = kernel_defn->lookup_variable_symbol("tid");
  assert(arg_tid_sym != NULL);
#endif

  for (it_loop_tiling = loop_tiling.begin(); it_loop_tiling != loop_tiling.end(); it_loop_tiling++) {
    LoopTrees::loop_t * loop = it_loop_tiling->first;
    LoopTiler::loop_tiling_t * tiling = it_loop_tiling->second;

    SgVariableSymbol * iter_sym = loop->iterator;
    std::string iter_name = iter_sym->get_name().getString();
    SgType * iter_type = iter_sym->get_type();

    std::ostringstream oss_loop;
    oss_loop << "it_" << loop->id;
    SgVariableSymbol * local_sym = Utils::getExistingSymbolOrBuildDecl(oss_loop.str(), iter_type, kernel_body);
    local_symbol_maps.iterators.insert(std::pair<SgVariableSymbol *, SgVariableSymbol *>(iter_sym, local_sym));

    size_t tile_cnt = 0;
    std::vector<Runtime::tile_desc_t>::iterator it_tile;
    for (it_tile = tiling->tiles.begin(); it_tile != tiling->tiles.end(); it_tile++) {
      std::ostringstream oss_tile;
      oss_tile << "it_" << loop->id << "_" << tile_cnt++;
      SgInitializer * init = NULL;
      if (it_tile->kind > 1) {
#ifdef TILEK_THREADS
        init = SageBuilder::buildAssignInitializer(SageBuilder::buildVarRefExp(arg_tid_sym));
#else
        assert(false);
#endif
      }
      it_tile->iterator_sym = Utils::getExistingSymbolOrBuildDecl(oss_tile.str(), iter_type, kernel_body, init);
    }
  }

  local_symbol_maps.context = kernel_defn->lookup_variable_symbol("context");
  assert(local_symbol_maps.context != NULL);

  return kernel_body;

}

} // namespace MFB

