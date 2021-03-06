include $(top_srcdir)/config/Makefile.for.ROSE.includes.and.libs

# This includes a standard list of tests for C++ code.
include $(top_srcdir)/tests/input_codes/cxx/Makefile_variables

# DQ (10/23/2013): Disable so that we can try an approach modifiying the original ATerm library to be ROSE specific.
# DQ (10/20/2013): Allow alternative support using ROSE ATerm library API.
SUBDIRS = roseAtermAPI

# DQ (10/20/2013): Allow alternative support using ROSE ATerm library API.
# The Stratego and A-Term support is outside of ROSE
# This needs a configure flag so that the location outside 
# of ROSE can be easily specificed at configure time.
# A_TERM_INCLUDE = -I$(ATERM_INSTALL_PATH)/include
# A_TERM_INCLUDE = -I$(srcdir)/roseAtermAPI
# A_TERM_INCLUDE = -I$(srcdir)/aterm-2.5/aterm
# A_TERM_INCLUDE = -I$(ATERM_INSTALL_PATH)/include

# INCLUDES = $(ROSE_INCLUDES) $(A_TERM_INCLUDE)
# INCLUDES = $(A_TERM_INCLUDE) $(ROSE_INCLUDES)
INCLUDES = $(ROSE_INCLUDES)

# bin_PROGRAMS = termToStratego strategoToTerm termGraph termGraph_using_RoseAtermAPI termGraph_using_RoseAtermAPI_withForwardedFunctions
# bin_PROGRAMS = termToStratego strategoToTerm termGraph termGraph_using_RoseAtermAPI testTranslation_AST_to_ATerm_to_AST testTranslation_AST_to_ATerm testTranslation_ATerm_to_AST
bin_PROGRAMS = testTranslation_AST_to_ATerm testTranslation_ATerm_to_AST termpretty

termToStratego_SOURCES = termToStratego.C astToAtermImpl.C atermTranslation.h

strategoToTerm_SOURCES = strategoToTerm.C atermToAstImpl.C atermTranslation.h

termGraph_SOURCES = termGraph.C

# termGraph_using_RoseAtermAPI_SOURCES = termGraph_using_RoseAtermAPI.C
termGraph_using_RoseAtermAPI_SOURCES = termGraph_using_RoseAtermAPI.C astToAtermImpl.C atermToAstImpl.C atermTranslation.h

# testTranslation_AST_to_ATerm_to_AST_SOURCES = testTranslation_AST_to_ATerm_to_AST.C astToAtermImpl.C atermToAstImpl.C atermTranslation.h
# testTranslation_AST_to_ATerm_SOURCES = testTranslation_AST_to_ATerm.C astToAtermImpl.C atermToAstImpl.C atermTranslation.h
# testTranslation_ATerm_to_AST_SOURCES = testTranslation_ATerm_to_AST.C astToAtermImpl.C atermToAstImpl.C atermTranslation.h
testTranslation_AST_to_ATerm_to_AST_SOURCES = testTranslation_AST_to_ATerm_to_AST.C atermTranslation.h
testTranslation_AST_to_ATerm_SOURCES = testTranslation_AST_to_ATerm.C atermTranslation.h
testTranslation_ATerm_to_AST_SOURCES = testTranslation_ATerm_to_AST.C atermTranslation.h

termpretty_SOURCES = termpretty.l++

# termGraph_using_RoseAtermAPI_withForwardedFunctions_SOURCES = termGraph_using_RoseAtermAPI_withForwardedFunctions.C

include_HEADERS = atermTranslation.h

ATERM_LIB_DIR = $(ATERM_INSTALL_PATH)/lib

LDADD = $(LIBS_WITH_RPATH) $(ROSE_LIBS) $(ATERM_LIB_DIR)/libATerm.a 

# DQ (9/17/2014): This is not inlcuded in the ROSE_LIBS list of libraries.
# Permit linking to alternative ROSE ATerm API used to support new non-serialized API for Stratego.
# termGraph_using_RoseAtermAPI_withForwardedFunctions_LDADD = $(LIBS_WITH_RPATH) $(ROSE_LIBS) ./roseAtermAPI/libATerm.la
# termGraph_using_RoseAtermAPI_LDADD = $(LIBS_WITH_RPATH) $(ROSE_LIBS) $(srcdir)/aterm-2.5/aterm/libATerm.la
termGraph_using_RoseAtermAPI_LDADD = $(LIBS_WITH_RPATH) $(ROSE_LIBS) 

# Added new test code to increase testing
testTranslation_AST_to_ATerm_to_AST_LDADD = $(LIBS_WITH_RPATH) $(ROSE_LIBS) 
# testTranslation_AST_to_ATerm_LDADD = $(LIBS_WITH_RPATH) $(ROSE_LIBS) 
# testTranslation_ATerm_to_AST_LDADD = $(LIBS_WITH_RPATH) $(ROSE_LIBS) 

# DQ (10/1/2014): This is the complete list of passing example codes.
COMPLETE_TESTCODES_REQUIRED_TO_PASS = \
test2013_01.C \
test2013_02.C \
test2013_03.C \
test2013_04.C \
test2014_01.C

TESTCODES_REQUIRED_TO_PASS = \
test2014_05.C

TESTCODE_CURRENTLY_FAILING =

# Automake's testing mechanism (which defines the "make check" rule) requires passing tests.
TESTCODES = $(TESTCODES_REQUIRED_TO_PASS)

ALL_TESTCODES = $(TESTCODES) $(TESTCODE_CURRENTLY_FAILING)

# PASSING_TEST_Output = $(addprefix rose_,${TESTCODES})
# TEST_Output = $(addprefix rose_,${ALL_TESTCODES})
PASSING_TEST_Output = $(TESTCODES_REQUIRED_TO_PASS)
TEST_Output = $(ALL_TESTCODES)
PASSING_TEST_Output = $(addsuffix .passed, $(filter-out $(TESTCODE_CURRENTLY_FAILING), $(ALL_TESTCODES)))

# rose_%: $(srcdir)/% termToStratego
#	./termToStratego $(ROSE_FLAGS) -c $< -o $@


REGRESSION_TESTCODES = \
test2001_01.C \
test2001_02.C \
test2001_03.C \
test2001_04.C \
test2001_05.C \
test2001_06.C \
test2001_07.C \
test2001_08.C \
test2001_09.C \
test2001_10.C \
test2001_11.C \
test2001_12.C \
test2001_13.C \
test2001_14.C \
test2001_15.C \
test2001_16.C \
test2001_17.C \
test2001_18.C \
test2001_19.C \
test2001_20.C \
test2001_21.C \
test2001_22.C \
test2001_23.C \
test2001_24.C \
test2001_25.C \
test2001_26.C \
test2001_27.C \
test2001_28.C \
test2001_29.C \
test2002_01.C \
test2003_01.C \
test2003_02.C \
test2003_03.C \
test2003_04.C \
test2003_05.C \
test2003_06.C \
test2003_08.C \
test2003_09.C \
test2003_10.C \
test2003_11.C \
test2003_12.C \
test2003_13.C \
test2003_14.C \
test2003_15.C \
test2003_16.C \
test2003_17.C \
test2003_18.C \
test2003_19.C \
test2003_20.C \
test2003_21.C \
test2003_23.C \
test2003_25.C \
test2003_26.C \
test2003_27.C \
test2003_28.C \
test2003_29.C \
test2003_30.C \
test2003_31.C \
test2003_32.C \
test2003_35.C \
test2003_36.C \
test2003_37.C \
test2003_38.C \
test2004_01.C \
test2004_02.C \
test2004_03.C \
test2004_04.C \
test2004_05.C \
test2004_06.C \
test2004_07.C \
test2004_08.C \
test2004_09.C \
test2004_10.C \
test2004_11.C \
test2004_12.C \
test2004_13.C \
test2004_14.C \
test2004_15.C \
test2004_16.C \
test2004_17.C \
test2004_18.C \
test2004_19.C \
test2004_23.C \
test2004_24.C \
test2004_26.C \
test2004_27.C \
test2004_28.C \
test2004_29.C \
test2004_30.C \
test2004_31.C \
test2004_32.C \
test2004_33.C \
test2004_34.C \
test2004_35.C \
test2004_36.C \
test2004_37.C \
test2004_38.C \
test2004_39.C \
test2004_40.C \
test2004_42.C \
test2004_43.C \
test2004_44.C \
test2004_45.C \
test2004_47.C \
test2004_48.C \
test2004_49.C \
test2004_50.C \
test2004_51.C \
test2004_52.C \
test2004_53.C \
test2004_54.C \
test2004_55.C \
test2004_56.C \
test2004_58.C \
test2004_59.C \
test2004_60.C \
test2004_61.C \
test2004_62.C \
test2004_63.C \
test2004_64.C \
test2004_65.C \
test2004_67.C \
test2004_68.C \
test2004_69.C \
test2004_70.C \
test2004_71.C \
test2004_72.C \
test2004_73.C \
test2004_74.C \
test2004_75.C \
test2004_76.C \
test2004_77.C \
test2004_78.C \
test2004_79.C \
test2004_80.C \
test2004_81.C \
test2004_83.C \
test2004_84.C \
test2004_86.C \
test2004_87.C \
test2004_88.C \
test2004_89.C \
test2004_90.C \
test2004_91.C \
test2004_93.C \
test2004_94.C \
test2004_95.C \
test2004_96.C \
test2004_97.C \
test2004_98.C \
test2004_99.C \
test2004_100.C \
test2004_101.C \
test2004_102.C \
test2004_103.C \
test2004_106.C \
test2004_107.C \
test2004_108.C \
test2004_109.C \
test2004_110.C \
test2004_111.C \
test2004_112.C \
test2004_113.C \
test2004_114.C \
test2004_115.C \
 test2004_116.C \
test2004_117.C \
test2004_118.C \
test2004_119.C \
test2004_121.C \
test2004_122.C \
test2004_123.C \
test2004_124.C \
test2004_125.C \
test2004_128.C \
test2004_131.C \
test2004_132.C \
test2004_133.C \
test2004_134.C \
test2004_135.C \
test2004_136.C \
test2004_137.C \
test2004_138.C \
test2004_139.C \
test2004_140.C \
test2004_141.C \
test2004_142.C \
 test2004_143.C \
test2004_144.C \
test2004_145.C \
test2004_146.C \
test2004_147.C \
test2004_148.C \
 test2004_149.C \
test2004_150.C \
test2004_151.C \
test2004_152.C \
test2004_153.C \
test2004_154.C \
test2004_155.C \
test2004_156.C \
test2004_157.C \
test2004_158.C \
test2004_159.C \
test2004_160.C \
test2004_161.C \
test2004_162.C \
test2004_163.C \
test2004_164.C \
test2005_01.C \
test2005_02.C \
test2005_03.C \
test2005_04.C \
test2005_05.C \
test2005_06.C \
test2005_07.C \
test2005_08.C \
test2005_10.C \
test2005_11.C \
test2005_12.C \
test2005_13.C \
test2005_14.C \
test2005_15.C \
test2005_16.C \
test2005_17.C \
test2005_19.C \
test2005_20.C \
test2005_21.C \
test2005_22.C \
test2005_23.C \
test2005_24.C \
test2005_25.C \
test2005_26.C \
test2005_27.C \
 test2005_28.C \
test2005_29.C \
test2005_30.C \
test2005_31.C \
test2005_33.C \
test2005_36.C \
test2005_37.C \
test2005_38.C \
 test2005_39.C \
test2005_40.C \
test2005_41.C \
 test2005_42.C \
test2005_43.C \
test2005_44.C \
test2005_45.C \
test2005_46.C \
test2005_47.C \
test2005_48.C \
test2005_49.C \
test2005_50.C \
test2005_51.C \
test2005_52.C \
test2005_53.C \
test2005_55.C \
test2005_57.C \
test2005_58.C \
test2005_59.C \
test2005_60.C \
test2005_61.C \
test2005_62.C \
test2005_63.C \
test2005_64.C \
test2005_65.C \
test2005_66.C \
test2005_67.C \
test2005_68.C \
test2005_70.C \
test2005_71.C \
test2005_72.C \
test2005_73.C \
test2005_74.C \
test2005_75a.C \
test2005_75b.C \
test2005_76.C \
test2005_77.C \
test2005_78.C \
test2005_79.C \
test2005_80.C \
test2005_81.C \
 test2005_82.C \
test2005_83.C \
test2005_84.C \
test2005_86.C \
test2005_87.C \
test2005_88.C \
test2005_89.C \
test2005_90.C \
test2005_91.C \
test2005_92.C \
 test2005_93.C \
test2005_94.C \
test2005_95.C \
test2005_96.C \
test2005_97.C \
test2005_98.C \
test2005_99.C \
test2005_100.C \
test2005_101.C \
test2005_102.C \
test2005_105.C \
test2005_106.C \
test2005_107.C \
test2005_108.C \
test2005_109.C \
test2005_110.C \
test2005_111.C \
test2005_113.C \
test2005_114.C \
test2005_116.C \
test2005_118.C \
test2005_119.C \
test2005_120.C \
test2005_121.C \
test2005_122.C \
test2005_123.C \
test2005_124.C \
test2005_125.C \
test2005_126.C \
test2005_127.C \
test2005_129.C \
test2005_130.C \
test2005_131.C \
test2005_132.C \
test2005_133.C \
test2005_134.C \
test2005_135.C \
test2005_136.C \
test2005_137.C \
test2005_138.C \
test2005_139.C \
test2005_140.C \
test2005_141.C \
test2005_143.C \
test2005_144.C \
test2005_145.C \
test2005_146.C \
test2005_147.C \
test2005_148.C \
test2005_149.C \
test2005_150.C \
test2005_152.C \
test2005_153.C \
test2005_155.C \
test2005_156.C \
test2005_157.C \
test2005_158.C \
test2005_159.C \
test2005_160.C \
test2005_162.C \
test2005_164.C \
test2005_165.C \
test2005_166.C \
test2005_168.C \
test2005_167.C \
test2005_169.C \
test2005_170.C \
test2005_171.C \
test2005_172.C \
test2005_173.C \
test2005_174.C \
test2005_175.C \
test2005_176.C \
test2005_177.C \
test2005_178.C \
test2005_180.C \
test2005_181.C \
test2005_182.C \
test2005_184.C \
test2005_185.C \
test2005_187.C \
test2005_189.C \
test2005_190.C \
test2005_191.C \
test2005_192.C \
test2005_193.C \
test2005_195.C \
   test2005_196.C \
test2005_197.C \
test2005_198.C \
test2005_202.C \
test2005_203.C \
   test2005_206.C \
   test2005_207.C \
test2005_208.C \
test2005_209.C \
test2006_01.C \
test2006_02.C \
test2006_03.C \
test2006_04.C \
test2006_05.C \
test2006_06.C \
test2006_07.C \
test2006_08.C \
test2006_10.C \
test2006_12.C \
test2006_13.C \
test2006_14.C \
test2006_16.C \
test2006_17.C \
test2006_18.C \
test2006_19.C \
test2006_20.C \
test2006_22.C \
test2006_23.C \
test2006_25.C \
test2006_26.C \
test2006_28.C \
test2006_34.C \
test2006_37.C \
test2006_38.C \
test2006_39.C \
test2006_40.C \
test2006_41.C \
test2006_42.C \
test2006_44.C \
test2006_46.C \
test2006_47.C \
test2006_50.C \
test2006_52.C \
test2006_54.C \
test2006_55.C \
test2006_56.C \
test2006_57.C \
test2006_58.C \
test2006_59.C \
test2006_61.C \
test2006_62.C \
test2006_63.C \
test2006_66.C \
test2006_67.C \
test2006_68.C \
test2006_69.C \
test2006_70.C \
test2006_71.C \
test2006_72.C \
test2006_73.C \
test2006_74.C \
test2006_75.C \
test2006_76.C \
test2006_77.C \
test2006_78.C \
test2006_79.C \
test2006_80.C \
test2006_81.C \
test2006_82.C \
test2006_83.C \
test2006_85.C \
test2006_87.C \
test2006_88.C \
test2006_89.C \
test2006_90.C \
test2006_91.C \
test2006_92.C \
test2006_93.C \
test2006_94.C \
test2006_95.C \
test2006_96.C \
test2006_97.C \
test2006_98.C \
test2006_99.C \
test2006_101.C \
test2006_102.C \
test2006_103.C \
test2006_104.C \
test2006_105.C \
test2006_106.C \
test2006_107.C \
test2006_108.C \
test2006_109.C \
test2006_111.C \
test2006_113.C \
test2006_114.C \
test2006_115.C \
test2006_116.C \
test2006_117.C \
test2006_118.C \
test2006_119.C \
test2006_120.C \
test2006_122.C \
test2006_123.C \
test2006_126.C \
test2006_129.C \
test2006_140.C \
test2006_142.C \
test2006_143.C \
test2006_144.C \
test2006_145.C \
test2006_146.C \
test2006_148.C \
test2006_149.C \
test2006_150.C \
test2006_152.C \
test2006_153.C \
test2006_154.C \
   test2006_155.C \
   test2006_156.C \
   test2006_157.C \
   test2006_158.C \
test2006_160.C \
test2006_161.C \
test2006_162.C \
test2006_163.C \
test2006_164.C \
test2006_165.C \
test2006_166.C \
test2006_177.C \
test2006_178.C \
test2006_179.C \
test2006_181.C \
test2006_183.C \
test2006_185.C \
test2006_189.C \
test2007_02.C \
test2007_03.C \
test2007_04.C \
test2007_06.C \
test2007_07.C \
test2007_08.C \
test2007_09.C \
test2007_10.C \
test2007_11.C \
test2007_12.C \
test2007_14.C \
   test2007_15.C \
test2007_16.C \
test2007_21.C \
test2007_23.C \
test2007_24.C \
test2007_25.C \
test2007_26.C \
test2007_28.C \
test2007_29.C \
test2007_38.C \
test2007_40.C \
test2007_41.C \
test2007_43.C \
test2007_44.C \
test2007_46.C \
test2007_47.C \
test2007_48.C \
test2007_49.C \
test2007_50.C \
test2007_51.C \
test2007_52.C \
test2007_53.C \
test2007_57.C \
test2007_59.C \
test2007_62.C \
test2007_70.C \
test2007_72.C \
test2007_75.C \
test2007_77.C \
test2007_81.C \
test2007_82.C \
test2007_83.C \
test2007_84.C \
test2007_85.C \
test2007_90.C \
test2007_94.C \
test2007_98.C \
test2007_102.C \
test2007_103.C \
test2007_128.C \
test2007_130.C \
test2007_133.C \
test2007_135.C \
test2007_137.C \
test2007_140.C \
test2007_141.C \
   test2007_142.C \
test2007_147.C \
test2007_150.C \
test2007_151.C \
test2007_152.C \
test2007_154.C \
test2007_155.C \
test2007_157.C \
test2007_158.C \
test2007_159.C \
test2007_160.C \
test2007_161.C \
test2007_162.C \
test2007_163.C \
test2007_164.C \
test2007_165.C \
test2007_166.C \
test2007_167.C \
test2007_169.C \
test2007_170.C \
test2007_171.C \
test2007_172.C \
test2007_173.C \
test2008_01.C \
test2008_03.C \
test2008_05.C \
test2008_06.C \
test2008_08.C \
test2008_09.C \
test2008_10.C \
test2008_11.C \
test2008_12.C \
test2008_13.C \
test2008_14.C \
test2008_16.C \
test2009_01.C \
test2009_02.C \
test2009_03.C \
test2009_04.C \
test2009_05.C \
test2009_06.C \
test2009_08.C \
test2009_09.C \
test2009_10.C \
test2009_11.C \
test2009_12.C \
test2009_14.C \
test2009_15.C \
test2009_18.C \
test2009_19.C \
test2009_20.C \
test2009_21.C \
test2009_24.C \
test2009_27.C \
test2009_28.C \
test2009_30.C \
test2009_39.C \
test2009_40.C \
test2009_42.C \
test2010_03.C \
test2010_04.C \
test2010_05.C \
test2010_06.C \
test2010_18.C \
test2010_19.C \
test2011_01.C \
test2011_02.C \
test2011_05.C \
test2011_06.C \
test2011_07.C \
test2011_19.C \
test2011_20.C \
test2011_21.C \
test2011_22.C \
test2011_23.C \
test2011_24.C \
test2011_25.C \
test2011_26.C \
test2011_27.C \
test2011_28.C \
test2011_29.C \
test2011_30.C \
test2011_31.C \
test2011_32.C \
test2011_33.C \
test2011_34.C \
test2011_35.C \
test2011_36.C \
test2011_37.C \
test2011_38.C \
test2011_39.C \
test2011_40.C \
test2011_41.C \
test2011_42.C \
test2011_43.C \
test2011_44.C \
test2011_45.C \
test2011_46.C \
test2011_47.C \
test2011_48.C \
test2011_49.C \
test2011_50.C \
test2011_51.C \
test2011_52.C \
test2011_53.C \
test2011_54.C \
test2011_55.C \
test2011_56.C \
test2011_57.C \
test2011_58.C \
test2011_59.C \
test2011_60.C \
test2011_61.C \
test2011_62.C \
test2011_63.C \
test2011_64.C \
test2011_67.C \
test2011_68.C \
test2011_69.C \
test2011_70.C \
test2011_71.C \
test2011_72.C \
test2011_73.C \
test2011_74.C \
test2011_75.C \
test2011_76.C \
test2011_77.C \
test2011_78.C \
test2011_79.C \
test2011_80.C \
test2011_81.C \
test2011_82.C \
test2011_83.C \
test2011_84.C \
test2011_85.C \
test2011_86.C \
test2011_87.C \
test2011_88.C \
test2011_90.C \
test2011_91.C \
test2011_92.C \
test2011_93.C \
test2011_94.C \
test2011_95.C \
test2011_96.C \
test2011_97.C \
test2011_98.C \
test2011_99.C \
test2011_100.C \
test2011_101.C \
test2011_110.C \
test2011_111.C \
test2011_115.C \
test2011_117.C \
test2011_118.C \
test2011_119.C \
test2011_120.C \
test2011_133.C \
test2011_135.C \
test2011_136.C \
test2011_137.C \
test2011_138.C \
test2011_139.C \
test2011_140.C \
test2011_143.C \
test2011_146.C \
test2011_147.C \
test2005_112.C \
test2005_117.C \
test2005_154.C \
test2005_163.C \
test2005_179.C \
test2005_183.C \
test2005_194.C \
test2005_199.C \
test2006_86.C \
test2006_121.C \
test2006_139.C \
test2006_147.C \
test2006_151.C \
test2006_159.C \
test2007_01.C \
test2007_13.C \
test2007_17.C \
test2007_55.C \
test2007_78.C \
test2008_04.C \
test_int_lexemes.C \
test_int_lexemes_donot_pass.C \
test_simple_int.C \
test_wchars.C \
lexPhase2003_01.C \
math.C \
inputForLoopLocator.C \
X.C \
inputBug327.C \
test2005_09.C \
test2005_104.C \
test2010_24.C 

# DQ (9/17/2014): These are new failing tests as a result of some chages to ROSE in 2014 (or since Sept 2013).
NEW_FAILING_TESTS = \
test2004_104.C \
test2004_105.C \
test2004_129.C \
test2005_34.C \
test2005_103.C \
test2005_142.C \
test2006_141.C \
test2009_41.C \
test2011_141.C \
test2011_142.C \
test2004_85.C

# DQ (9/17/2014): These are failing tests as of September 2013.
FAILING_TESTS = \
test2004_120.C \
test2004_127.C \
test2005_35.C \
test2005_128.C \
test2006_53.C \
test2006_84.C \
test2006_124.C \
inputBug317.C 

REGRESSION_C_SUBSET_OF_CXX_TESTCODES = \
test_CplusplusMacro_C.C \
test2001_02.C \
test2001_03.C \
test2001_05.C \
test2001_07.C \
test2001_08.C \
test2001_09.C \
test2001_14.C \
test2001_17.C \
test2001_23.C \
test2001_24.C \
test2001_25.C \
test2001_26.C \
test2002_01.C \
test2003_04.C \
test2003_05.C \
test2003_06.C \
test2003_10.C \
test2003_11.C \
test2003_13.C \
test2003_14.C \
test2003_15.C \
test2003_16.C \
test2003_18.C \
test2003_19.C \
test2003_20.C \
test2003_21.C \
test2003_23.C \
test2003_24.C \
test2003_25.C \
test2003_26.C \
test2003_29.C \
test2003_30.C \
test2003_31.C \
test2003_32.C \
test2003_35.C \
test2003_36.C \
test2004_03.C \
test2004_04.C \
test2004_05.C \
test2004_13.C \
test2004_14.C \
test2004_19.C \
test2004_23.C \
test2004_28.C \
test2004_29.C \
test2004_49.C \
test2004_53.C \
test2004_60.C \
test2004_61.C \
test2004_72.C \
test2004_74.C \
test2004_94.C \
test2004_96.C \
test2004_102.C \
test2004_105.C \
test2004_107.C \
test2004_108.C \
test2004_114.C \
test2004_118.C \
test2004_131.C \
test2004_152.C \
test2004_153.C \
test2004_154.C \
test2004_163.C \
test2005_16.C \
test2005_20.C \
test2005_21.C \
test2005_22.C \
test2005_23.C \
test2005_26.C \
test2005_48.C \
test2005_62.C \
test2005_84.C \
test2005_92.C \
test2005_95.C \
test2005_100.C \
test2005_111.C \
test2005_116.C \
test2005_125.C \
test2005_157.C \
test2005_159.C \
test2005_164.C \
test2005_165.C \
test2005_169.C \
test2005_170.C \
test2005_176.C \
test2005_180.C \
test2005_182.C \
test2005_184.C \
test2005_187.C \
test2005_191.C \
test2005_198.C \
test2005_202.C \
test2005_209.C \
test2006_07.C \
test2006_10.C \
test2006_12.C \
test2006_14.C \
test2006_16.C \
test2006_23.C \
test2006_34.C \
test2006_40.C \
test2006_50.C \
test2006_52.C \
test2006_53.C \
test2006_55.C \
test2006_56.C \
test2006_57.C \
test2006_62.C \
test2006_69.C \
test2006_75.C \
test2006_76.C \
test2006_82.C \
test2006_83.C \
test2006_88.C \
test2006_91.C \
test2006_93.C \
test2006_94.C \
test2006_97.C \
test2006_99.C \
test2006_103.C \
test2006_104.C \
test2006_105.C \
test2006_106.C \
test2006_107.C \
test2006_108.C \
test2006_109.C \
test2006_111.C \
test2006_113.C \
test2006_116.C \
test2006_137.C \
test2006_140.C \
test2006_142.C \
test2006_145.C \
test2006_146.C \
test2006_147.C \
test2006_148.C \
test2006_149.C \
test2006_150.C \
test2006_151.C \
test2006_152.C \
test2006_153.C \
test2006_154.C \
test2006_181.C \
test2008_04.C \
test2010_16.C \
test_int_lexemes.C \
test_int_lexemes_donot_pass.C \
test_simple_int.C \
test_wchars.C \
X.C

# DQ (9/29/2014): This test code required the TEST_STRING_MACRO macro to be defined on the command line (ignore it for these ATerm tests).
# test2005_56.C 

#PASSING_REGRESSION_TEST_Output = $(addprefix rose_,${REGRESSION_TESTCODES})
# PASSING_REGRESSION_TEST_Output = ${REGRESSION_TESTCODES}
# PASSING_TEST_Objects = ${TESTCODES:.C=.o} ${ROSE__CXX_TESTS__BOOST:.C=.o}
# PASSING_REGRESSION_TEST_Output = ${REGRESSION_TESTCODES:.C=.C.dot} ${ROSE__CXX_TESTS:.C=.C.dot}
PASSING_REGRESSION_TEST_Output = ${REGRESSION_TESTCODES:.C=.C.dot} 
PASSING_REGRESSION_TEST_ATerm_Output = ${REGRESSION_TESTCODES:.C=.C.dot} 

# PASSING_REGRESSION_TEST_AST_Output = ${REGRESSION_TESTCODES:.C=.C.dot}
TESTS_THAT_FAIL =
PASSING_REGRESSION_TEST_AST_Output = $(addsuffix .passed, $(filter-out $(TESTS_THAT_FAIL), $(REGRESSION_TESTCODES)))


PASSING_REGRESSION_C_SUBSET_OF_CXX_TEST_Output = ${REGRESSION_C_SUBSET_OF_CXX_TESTCODES:.C=.C.dot}
PASSING_REGRESSION_C_SUBSET_OF_CXX_TEST_ATerm_Output = ${REGRESSION_C_SUBSET_OF_CXX_TESTCODES:.C=.C.dot}

# rose_%: $(srcdir)/tests/CompileTests/Cxx_tests/% ./termGraph_using_RoseAtermAPI
#$(PASSING_REGRESSION_TEST_Output): ./termGraph_using_RoseAtermAPI
#	./termGraph_using_RoseAtermAPI $(ROSE_FLAGS) $(srcdir)/tests/CompileTests/Cxx_tests/$@
#$(PASSING_REGRESSION_TEST_Output): ./termGraph_using_RoseAtermAPI
#	./termGraph_using_RoseAtermAPI $(ROSE_FLAGS) -c $(top_srcdir)/tests/CompileTests/Cxx_tests/test2001_01.C
# $(PASSING_REGRESSION_TEST_Output): ./termGraph_using_RoseAtermAPI
$(PASSING_REGRESSION_TEST_Output): 
	./termGraph_using_RoseAtermAPI $(ROSE_FLAGS) -I$(top_srcdir)/tests/CompileTests/Cxx_tests -c $(top_srcdir)/tests/CompileTests/Cxx_tests/$(@:.C.dot=.C)

$(PASSING_REGRESSION_TEST_ATerm_Output): ./testTranslation_AST_to_ATerm
	./testTranslation_AST_to_ATerm $(ROSE_FLAGS) -I$(top_srcdir)/tests/CompileTests/Cxx_tests -c $(top_srcdir)/tests/CompileTests/Cxx_tests/$(@:.C.dot=.C)

$(PASSING_REGRESSION_TEST_AST_Output): ./testTranslation_ATerm_to_AST
	./testTranslation_AST_to_ATerm $(ROSE_FLAGS) -I$(top_srcdir)/tests/CompileTests/Cxx_tests -c $(top_srcdir)/tests/CompileTests/Cxx_tests/$(@:.C.passed=.C)
#	./testTranslation_ATerm_to_AST $(@:.C.dot=.C_TAF.aterm)
	@$(RTH_RUN) CMD="./testTranslation_ATerm_to_AST $(@:.C.passed=.C_TAF.aterm)" $(top_srcdir)/scripts/test_exit_status $@

$(PASSING_TEST_Output): ./testTranslation_ATerm_to_AST ./testTranslation_AST_to_ATerm
	./testTranslation_AST_to_ATerm $(ROSE_FLAGS) -c $(srcdir)/$(@:.C.passed=.C)
#	./testTranslation_ATerm_to_AST $(@:.C.dot=.C_TAF.aterm)
	@$(RTH_RUN) CMD="./testTranslation_ATerm_to_AST $(@:.C.passed=.C_TAF.aterm)" $(top_srcdir)/scripts/test_exit_status $@

# $(PASSING_REGRESSION_C_SUBSET_OF_CXX_TEST_Output): ./termGraph_using_RoseAtermAPI
#	@echo "Part 1: Copy the file to the local build tree so that we can change the file name suffix (to be a C language file) ..."
#	cp $(top_srcdir)/tests/CompileTests/Cxx_tests/$(@:.C.dot=.C) $(@:.C.dot=.c)
#	./termGraph_using_RoseAtermAPI $(ROSE_FLAGS) -I$(top_srcdir)/tests/CompileTests/Cxx_tests -c $(@:.C.dot=.c)
#	rm -f $(@:.C.dot=.c)

# $(PASSING_REGRESSION_C_SUBSET_OF_CXX_TEST_ATerm_Output): ./termGraph_using_RoseAtermAPI
#	@echo "Part 2: Copy the file to the local build tree so that we can change the file name suffix (to be a C language file) ..."
#	cp $(top_srcdir)/tests/CompileTests/Cxx_tests/$(@:.C.dot=.C) $(@:.C.dot=.c)
#	./testTranslation_AST_to_ATerm $(ROSE_FLAGS) -I$(top_srcdir)/tests/CompileTests/Cxx_tests -c $(@:.C.dot=.c)
#	rm -f $(@:.C.dot=.c)

# $(TEST_Output): ../../testTranslator $(srcdir)/$(@:rose_%=%)
# ../../testTranslator -rose:UPC $(ROSE_FLAGS) -c $(srcdir)/$(@:rose_%=%)
../../testTranslator:
	cd ../..; $(MAKE) testTranslator


test1: testTranslation_AST_to_ATerm_to_AST
#	./termGraph_using_RoseAtermAPI $(ROSE_FLAGS) -I$(top_srcdir)/tests/CompileTests/Cxx_tests -c $(srcdir)/test2013_01.C
	./testTranslation_AST_to_ATerm_to_AST $(ROSE_FLAGS) -I$(top_srcdir)/tests/CompileTests/Cxx_tests -c $(srcdir)/test2013_01.C

test2: testTranslation_AST_to_ATerm_to_AST
	@echo "Tests for ATerm C examples."
#	@$(MAKE) $(PASSING_REGRESSION_C_SUBSET_OF_CXX_TEST_Output)
	@$(MAKE) $(PASSING_REGRESSION_TEST_ATerm_Output)

test3: testTranslation_ATerm_to_AST
	@echo "Tests for ATerm to ROSE examples."
	@$(MAKE) $(PASSING_REGRESSION_TEST_AST_Output)

test4: testTranslation_ATerm_to_AST testTranslation_AST_to_ATerm
	@$(MAKE) $(PASSING_TEST_Output)

test: termGraph
	./termGraph atermFile.aterm

testAPI: ./termGraph_using_RoseAtermAPI
	./termGraph_using_RoseAtermAPI $(srcdir)/test2013_01.C

# This test demonstrate the use of forwarded function more similar to the paper (but for C instead of Java).
# testAPI_withForwardedFunctions: ./termGraph_using_RoseAtermAPI_withForwardedFunctions
# 	./termGraph_using_RoseAtermAPI_withForwardedFunctions $(srcdir)/test2013_01.C



if ROSE_WITH_ATERM
status:
	echo "ROSE_WITH_ATERM is defined"
endif

check-local:
	@echo "Tests for ATerm examples."
#	@$(MAKE) $(PASSING_TEST_Output)
#	@$(MAKE) $(PASSING_REGRESSION_TEST_Output)
#	@$(MAKE) $(PASSING_REGRESSION_C_SUBSET_OF_CXX_TEST_Output)
	@$(MAKE) $(PASSING_REGRESSION_TEST_ATerm_Output)
#	@$(MAKE) $(PASSING_REGRESSION_C_SUBSET_OF_CXX_TEST_ATerm_Output)
#	@$(MAKE) $(PASSING_REGRESSION_TEST_ATerm_Output)
	@echo "********************************************************************************************"
	@echo "****** ROSE/projects/AtermTranslation: make check rule complete (terminated normally) ******"
	@echo "********************************************************************************************"


EXTRA_DIST = 
CLEANFILES = 

clean-local:
	rm -rf Templates.DB ii_files ti_files rose_*.C *.pdf
	rm -f a.out *.dot *.aterm *.failed *.passed

clean_tests:
	rm -f a.out *.dot *.aterm *.failed *.passed

# rule to compile stretego program to generate a C file 
# which stretego compiles to generate an executable.
strtest1$(EXEEXT): strtest1.str
	strc -i strtest1


