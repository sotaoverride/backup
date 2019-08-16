#ifndef TARGET_ASM_OPEN_PAREN
#define TARGET_ASM_OPEN_PAREN "("
#endif
#ifndef TARGET_ASM_CLOSE_PAREN
#define TARGET_ASM_CLOSE_PAREN ")"
#endif
#ifndef TARGET_ASM_BYTE_OP
#define TARGET_ASM_BYTE_OP "\t.byte\t"
#endif
#ifndef TARGET_ASM_ALIGNED_OP
#define TARGET_ASM_ALIGNED_OP TARGET_ASM_ALIGNED_INT_OP
#endif
#ifndef TARGET_ASM_UNALIGNED_OP
#define TARGET_ASM_UNALIGNED_OP TARGET_ASM_UNALIGNED_INT_OP
#endif
#ifndef TARGET_ASM_INTEGER
#define TARGET_ASM_INTEGER default_assemble_integer
#endif
#ifndef TARGET_ASM_POST_CFI_STARTPROC
#define TARGET_ASM_POST_CFI_STARTPROC hook_void_FILEptr_tree
#endif
#ifndef TARGET_ASM_DECL_END
#define TARGET_ASM_DECL_END hook_void_void
#endif
#ifndef TARGET_ASM_GLOBALIZE_LABEL
#define TARGET_ASM_GLOBALIZE_LABEL default_globalize_label
#endif
#ifndef TARGET_ASM_GLOBALIZE_DECL_NAME
#define TARGET_ASM_GLOBALIZE_DECL_NAME default_globalize_decl_name
#endif
#ifndef TARGET_ASM_ASSEMBLE_UNDEFINED_DECL
#define TARGET_ASM_ASSEMBLE_UNDEFINED_DECL                                     \
    hook_void_FILEptr_constcharptr_const_tree
#endif
#ifndef TARGET_ASM_EMIT_UNWIND_LABEL
#define TARGET_ASM_EMIT_UNWIND_LABEL default_emit_unwind_label
#endif
#ifndef TARGET_ASM_EMIT_EXCEPT_TABLE_LABEL
#define TARGET_ASM_EMIT_EXCEPT_TABLE_LABEL default_emit_except_table_label
#endif
#ifndef TARGET_ASM_EMIT_EXCEPT_PERSONALITY
#define TARGET_ASM_EMIT_EXCEPT_PERSONALITY NULL
#endif
#ifndef TARGET_ASM_UNWIND_EMIT
#define TARGET_ASM_UNWIND_EMIT NULL
#endif
#ifndef TARGET_ASM_UNWIND_EMIT_BEFORE_INSN
#define TARGET_ASM_UNWIND_EMIT_BEFORE_INSN true
#endif
#ifndef TARGET_ASM_GENERATE_INTERNAL_LABEL
#define TARGET_ASM_GENERATE_INTERNAL_LABEL default_generate_internal_label
#endif
#ifndef TARGET_ASM_INTERNAL_LABEL
#define TARGET_ASM_INTERNAL_LABEL default_internal_label
#endif
#ifndef TARGET_ASM_DECLARE_CONSTANT_NAME
#define TARGET_ASM_DECLARE_CONSTANT_NAME default_asm_declare_constant_name
#endif
#ifndef TARGET_ASM_TTYPE
#define TARGET_ASM_TTYPE hook_bool_rtx_false
#endif
#ifndef TARGET_ASM_ASSEMBLE_VISIBILITY
#define TARGET_ASM_ASSEMBLE_VISIBILITY default_assemble_visibility
#endif
#ifndef TARGET_ASM_PRINT_PATCHABLE_FUNCTION_ENTRY
#define TARGET_ASM_PRINT_PATCHABLE_FUNCTION_ENTRY                              \
    default_print_patchable_function_entry
#endif
#ifndef TARGET_ASM_FUNCTION_PROLOGUE
#define TARGET_ASM_FUNCTION_PROLOGUE default_function_pro_epilogue
#endif
#ifndef TARGET_ASM_FUNCTION_END_PROLOGUE
#define TARGET_ASM_FUNCTION_END_PROLOGUE no_asm_to_stream
#endif
#ifndef TARGET_ASM_FUNCTION_BEGIN_EPILOGUE
#define TARGET_ASM_FUNCTION_BEGIN_EPILOGUE no_asm_to_stream
#endif
#ifndef TARGET_ASM_FUNCTION_EPILOGUE
#define TARGET_ASM_FUNCTION_EPILOGUE default_function_pro_epilogue
#endif
#ifndef TARGET_ASM_INIT_SECTIONS
#define TARGET_ASM_INIT_SECTIONS hook_void_void
#endif
#ifndef TARGET_ASM_NAMED_SECTION
#define TARGET_ASM_NAMED_SECTION default_no_named_section
#endif
#ifndef TARGET_ASM_ELF_FLAGS_NUMERIC
#define TARGET_ASM_ELF_FLAGS_NUMERIC hook_bool_uint_uintp_false
#endif
#ifndef TARGET_ASM_FUNCTION_SECTION
#define TARGET_ASM_FUNCTION_SECTION default_function_section
#endif
#ifndef TARGET_ASM_FUNCTION_SWITCHED_TEXT_SECTIONS
#define TARGET_ASM_FUNCTION_SWITCHED_TEXT_SECTIONS                             \
    default_function_switched_text_sections
#endif
#ifndef TARGET_ASM_RELOC_RW_MASK
#define TARGET_ASM_RELOC_RW_MASK default_reloc_rw_mask
#endif
#ifndef TARGET_ASM_GENERATE_PIC_ADDR_DIFF_VEC
#define TARGET_ASM_GENERATE_PIC_ADDR_DIFF_VEC default_generate_pic_addr_diff_vec
#endif
#ifndef TARGET_ASM_SELECT_SECTION
#define TARGET_ASM_SELECT_SECTION default_select_section
#endif
#ifndef TARGET_ASM_SELECT_RTX_SECTION
#define TARGET_ASM_SELECT_RTX_SECTION default_select_rtx_section
#endif
#ifndef TARGET_ASM_UNIQUE_SECTION
#define TARGET_ASM_UNIQUE_SECTION default_unique_section
#endif
#ifndef TARGET_ASM_FUNCTION_RODATA_SECTION
#define TARGET_ASM_FUNCTION_RODATA_SECTION default_function_rodata_section
#endif
#ifndef TARGET_ASM_MERGEABLE_RODATA_PREFIX
#define TARGET_ASM_MERGEABLE_RODATA_PREFIX ".rodata"
#endif
#ifndef TARGET_ASM_TM_CLONE_TABLE_SECTION
#define TARGET_ASM_TM_CLONE_TABLE_SECTION default_clone_table_section
#endif
#ifndef TARGET_ASM_CONSTRUCTOR
#define TARGET_ASM_CONSTRUCTOR NULL
#endif
#ifndef TARGET_ASM_DESTRUCTOR
#define TARGET_ASM_DESTRUCTOR NULL
#endif
#ifndef TARGET_ASM_OUTPUT_MI_THUNK
#define TARGET_ASM_OUTPUT_MI_THUNK NULL
#endif
#ifndef TARGET_ASM_CAN_OUTPUT_MI_THUNK
#define TARGET_ASM_CAN_OUTPUT_MI_THUNK                                         \
    hook_bool_const_tree_hwi_hwi_const_tree_false
#endif
#ifndef TARGET_ASM_FILE_START
#define TARGET_ASM_FILE_START default_file_start
#endif
#ifndef TARGET_ASM_FILE_END
#define TARGET_ASM_FILE_END hook_void_void
#endif
#ifndef TARGET_ASM_LTO_START
#define TARGET_ASM_LTO_START hook_void_void
#endif
#ifndef TARGET_ASM_LTO_END
#define TARGET_ASM_LTO_END hook_void_void
#endif
#ifndef TARGET_ASM_CODE_END
#define TARGET_ASM_CODE_END hook_void_void
#endif
#ifndef TARGET_ASM_EXTERNAL_LIBCALL
#define TARGET_ASM_EXTERNAL_LIBCALL default_external_libcall
#endif
#ifndef TARGET_ASM_MARK_DECL_PRESERVED
#define TARGET_ASM_MARK_DECL_PRESERVED hook_void_constcharptr
#endif
#ifndef TARGET_ASM_RECORD_GCC_SWITCHES
#define TARGET_ASM_RECORD_GCC_SWITCHES NULL
#endif
#ifndef TARGET_ASM_RECORD_GCC_SWITCHES_SECTION
#define TARGET_ASM_RECORD_GCC_SWITCHES_SECTION ".GCC.command.line"
#endif
#ifndef TARGET_ASM_OUTPUT_ANCHOR
#define TARGET_ASM_OUTPUT_ANCHOR default_asm_output_anchor
#endif
#ifndef TARGET_ASM_OUTPUT_IDENT
#define TARGET_ASM_OUTPUT_IDENT hook_void_constcharptr
#endif
#ifndef TARGET_ASM_OUTPUT_DWARF_DTPREL
#define TARGET_ASM_OUTPUT_DWARF_DTPREL NULL
#endif
#ifndef TARGET_ASM_FINAL_POSTSCAN_INSN
#define TARGET_ASM_FINAL_POSTSCAN_INSN NULL
#endif
#ifndef TARGET_ASM_TRAMPOLINE_TEMPLATE
#define TARGET_ASM_TRAMPOLINE_TEMPLATE NULL
#endif
#ifndef TARGET_ASM_OUTPUT_SOURCE_FILENAME
#define TARGET_ASM_OUTPUT_SOURCE_FILENAME default_asm_output_source_filename
#endif
#ifndef TARGET_ASM_OUTPUT_ADDR_CONST_EXTRA
#define TARGET_ASM_OUTPUT_ADDR_CONST_EXTRA hook_bool_FILEptr_rtx_false
#endif
#ifndef TARGET_PRINT_OPERAND
#define TARGET_PRINT_OPERAND default_print_operand
#endif
#ifndef TARGET_PRINT_OPERAND_ADDRESS
#define TARGET_PRINT_OPERAND_ADDRESS default_print_operand_address
#endif
#ifndef TARGET_PRINT_OPERAND_PUNCT_VALID_P
#define TARGET_PRINT_OPERAND_PUNCT_VALID_P default_print_operand_punct_valid_p
#endif
#ifndef TARGET_MANGLE_ASSEMBLER_NAME
#define TARGET_MANGLE_ASSEMBLER_NAME default_mangle_assembler_name
#endif
#ifndef TARGET_SCHED_ADJUST_COST
#define TARGET_SCHED_ADJUST_COST NULL
#endif
#ifndef TARGET_SCHED_ADJUST_PRIORITY
#define TARGET_SCHED_ADJUST_PRIORITY NULL
#endif
#ifndef TARGET_SCHED_ISSUE_RATE
#define TARGET_SCHED_ISSUE_RATE NULL
#endif
#ifndef TARGET_SCHED_VARIABLE_ISSUE
#define TARGET_SCHED_VARIABLE_ISSUE NULL
#endif
#ifndef TARGET_SCHED_INIT
#define TARGET_SCHED_INIT NULL
#endif
#ifndef TARGET_SCHED_FINISH
#define TARGET_SCHED_FINISH NULL
#endif
#ifndef TARGET_SCHED_INIT_GLOBAL
#define TARGET_SCHED_INIT_GLOBAL NULL
#endif
#ifndef TARGET_SCHED_FINISH_GLOBAL
#define TARGET_SCHED_FINISH_GLOBAL NULL
#endif
#ifndef TARGET_SCHED_REORDER
#define TARGET_SCHED_REORDER NULL
#endif
#ifndef TARGET_SCHED_REORDER2
#define TARGET_SCHED_REORDER2 NULL
#endif
#ifndef TARGET_SCHED_MACRO_FUSION_P
#define TARGET_SCHED_MACRO_FUSION_P NULL
#endif
#ifndef TARGET_SCHED_MACRO_FUSION_PAIR_P
#define TARGET_SCHED_MACRO_FUSION_PAIR_P NULL
#endif
#ifndef TARGET_SCHED_DEPENDENCIES_EVALUATION_HOOK
#define TARGET_SCHED_DEPENDENCIES_EVALUATION_HOOK NULL
#endif
#ifndef TARGET_SCHED_INIT_DFA_PRE_CYCLE_INSN
#define TARGET_SCHED_INIT_DFA_PRE_CYCLE_INSN NULL
#endif
#ifndef TARGET_SCHED_DFA_PRE_CYCLE_INSN
#define TARGET_SCHED_DFA_PRE_CYCLE_INSN NULL
#endif
#ifndef TARGET_SCHED_INIT_DFA_POST_CYCLE_INSN
#define TARGET_SCHED_INIT_DFA_POST_CYCLE_INSN NULL
#endif
#ifndef TARGET_SCHED_DFA_POST_CYCLE_INSN
#define TARGET_SCHED_DFA_POST_CYCLE_INSN NULL
#endif
#ifndef TARGET_SCHED_DFA_PRE_ADVANCE_CYCLE
#define TARGET_SCHED_DFA_PRE_ADVANCE_CYCLE NULL
#endif
#ifndef TARGET_SCHED_DFA_POST_ADVANCE_CYCLE
#define TARGET_SCHED_DFA_POST_ADVANCE_CYCLE NULL
#endif
#ifndef TARGET_SCHED_FIRST_CYCLE_MULTIPASS_DFA_LOOKAHEAD
#define TARGET_SCHED_FIRST_CYCLE_MULTIPASS_DFA_LOOKAHEAD NULL
#endif
#ifndef TARGET_SCHED_FIRST_CYCLE_MULTIPASS_DFA_LOOKAHEAD_GUARD
#define TARGET_SCHED_FIRST_CYCLE_MULTIPASS_DFA_LOOKAHEAD_GUARD NULL
#endif
#ifndef TARGET_SCHED_FIRST_CYCLE_MULTIPASS_BEGIN
#define TARGET_SCHED_FIRST_CYCLE_MULTIPASS_BEGIN NULL
#endif
#ifndef TARGET_SCHED_FIRST_CYCLE_MULTIPASS_ISSUE
#define TARGET_SCHED_FIRST_CYCLE_MULTIPASS_ISSUE NULL
#endif
#ifndef TARGET_SCHED_FIRST_CYCLE_MULTIPASS_BACKTRACK
#define TARGET_SCHED_FIRST_CYCLE_MULTIPASS_BACKTRACK NULL
#endif
#ifndef TARGET_SCHED_FIRST_CYCLE_MULTIPASS_END
#define TARGET_SCHED_FIRST_CYCLE_MULTIPASS_END NULL
#endif
#ifndef TARGET_SCHED_FIRST_CYCLE_MULTIPASS_INIT
#define TARGET_SCHED_FIRST_CYCLE_MULTIPASS_INIT NULL
#endif
#ifndef TARGET_SCHED_FIRST_CYCLE_MULTIPASS_FINI
#define TARGET_SCHED_FIRST_CYCLE_MULTIPASS_FINI NULL
#endif
#ifndef TARGET_SCHED_DFA_NEW_CYCLE
#define TARGET_SCHED_DFA_NEW_CYCLE NULL
#endif
#ifndef TARGET_SCHED_IS_COSTLY_DEPENDENCE
#define TARGET_SCHED_IS_COSTLY_DEPENDENCE NULL
#endif
#ifndef TARGET_SCHED_H_I_D_EXTENDED
#define TARGET_SCHED_H_I_D_EXTENDED NULL
#endif
#ifndef TARGET_SCHED_ALLOC_SCHED_CONTEXT
#define TARGET_SCHED_ALLOC_SCHED_CONTEXT NULL
#endif
#ifndef TARGET_SCHED_INIT_SCHED_CONTEXT
#define TARGET_SCHED_INIT_SCHED_CONTEXT NULL
#endif
#ifndef TARGET_SCHED_SET_SCHED_CONTEXT
#define TARGET_SCHED_SET_SCHED_CONTEXT NULL
#endif
#ifndef TARGET_SCHED_CLEAR_SCHED_CONTEXT
#define TARGET_SCHED_CLEAR_SCHED_CONTEXT NULL
#endif
#ifndef TARGET_SCHED_FREE_SCHED_CONTEXT
#define TARGET_SCHED_FREE_SCHED_CONTEXT NULL
#endif
#ifndef TARGET_SCHED_SPECULATE_INSN
#define TARGET_SCHED_SPECULATE_INSN NULL
#endif
#ifndef TARGET_SCHED_NEEDS_BLOCK_P
#define TARGET_SCHED_NEEDS_BLOCK_P NULL
#endif
#ifndef TARGET_SCHED_GEN_SPEC_CHECK
#define TARGET_SCHED_GEN_SPEC_CHECK NULL
#endif
#ifndef TARGET_SCHED_SET_SCHED_FLAGS
#define TARGET_SCHED_SET_SCHED_FLAGS NULL
#endif
#ifndef TARGET_SCHED_GET_INSN_SPEC_DS
#define TARGET_SCHED_GET_INSN_SPEC_DS NULL
#endif
#ifndef TARGET_SCHED_GET_INSN_CHECKED_DS
#define TARGET_SCHED_GET_INSN_CHECKED_DS NULL
#endif
#ifndef TARGET_SCHED_CAN_SPECULATE_INSN
#define TARGET_SCHED_CAN_SPECULATE_INSN hook_bool_rtx_insn_true
#endif
#ifndef TARGET_SCHED_SKIP_RTX_P
#define TARGET_SCHED_SKIP_RTX_P NULL
#endif
#ifndef TARGET_SCHED_SMS_RES_MII
#define TARGET_SCHED_SMS_RES_MII NULL
#endif
#ifndef TARGET_SCHED_DISPATCH_DO
#define TARGET_SCHED_DISPATCH_DO hook_void_rtx_insn_int
#endif
#ifndef TARGET_SCHED_DISPATCH
#define TARGET_SCHED_DISPATCH hook_bool_rtx_insn_int_false
#endif
#ifndef TARGET_SCHED_EXPOSED_PIPELINE
#define TARGET_SCHED_EXPOSED_PIPELINE false
#endif
#ifndef TARGET_SCHED_REASSOCIATION_WIDTH
#define TARGET_SCHED_REASSOCIATION_WIDTH hook_int_uint_mode_1
#endif
#ifndef TARGET_SCHED_FUSION_PRIORITY
#define TARGET_SCHED_FUSION_PRIORITY NULL
#endif
#ifndef TARGET_SIMD_CLONE_COMPUTE_VECSIZE_AND_SIMDLEN
#define TARGET_SIMD_CLONE_COMPUTE_VECSIZE_AND_SIMDLEN NULL
#endif
#ifndef TARGET_SIMD_CLONE_ADJUST
#define TARGET_SIMD_CLONE_ADJUST NULL
#endif
#ifndef TARGET_SIMD_CLONE_USABLE
#define TARGET_SIMD_CLONE_USABLE NULL
#endif
#ifndef TARGET_SIMT_VF
#define TARGET_SIMT_VF NULL
#endif
#ifndef TARGET_GOACC_VALIDATE_DIMS
#define TARGET_GOACC_VALIDATE_DIMS default_goacc_validate_dims
#endif
#ifndef TARGET_GOACC_DIM_LIMIT
#define TARGET_GOACC_DIM_LIMIT default_goacc_dim_limit
#endif
#ifndef TARGET_GOACC_FORK_JOIN
#define TARGET_GOACC_FORK_JOIN default_goacc_fork_join
#endif
#ifndef TARGET_GOACC_REDUCTION
#define TARGET_GOACC_REDUCTION default_goacc_reduction
#endif
#ifndef TARGET_VECTORIZE_BUILTIN_MASK_FOR_LOAD
#define TARGET_VECTORIZE_BUILTIN_MASK_FOR_LOAD NULL
#endif
#ifndef TARGET_VECTORIZE_BUILTIN_VECTORIZED_FUNCTION
#define TARGET_VECTORIZE_BUILTIN_VECTORIZED_FUNCTION                           \
    default_builtin_vectorized_function
#endif
#ifndef TARGET_VECTORIZE_BUILTIN_MD_VECTORIZED_FUNCTION
#define TARGET_VECTORIZE_BUILTIN_MD_VECTORIZED_FUNCTION                        \
    default_builtin_md_vectorized_function
#endif
#ifndef TARGET_VECTORIZE_BUILTIN_CONVERSION
#define TARGET_VECTORIZE_BUILTIN_CONVERSION                                    \
    default_builtin_vectorized_conversion
#endif
#ifndef TARGET_VECTORIZE_BUILTIN_VECTORIZATION_COST
#define TARGET_VECTORIZE_BUILTIN_VECTORIZATION_COST                            \
    default_builtin_vectorization_cost
#endif
#ifndef TARGET_VECTORIZE_PREFERRED_VECTOR_ALIGNMENT
#define TARGET_VECTORIZE_PREFERRED_VECTOR_ALIGNMENT                            \
    default_preferred_vector_alignment
#endif
#ifndef TARGET_VECTORIZE_VECTOR_ALIGNMENT_REACHABLE
#define TARGET_VECTORIZE_VECTOR_ALIGNMENT_REACHABLE                            \
    default_builtin_vector_alignment_reachable
#endif
#ifndef TARGET_VECTORIZE_VEC_PERM_CONST
#define TARGET_VECTORIZE_VEC_PERM_CONST NULL
#endif
#ifndef TARGET_VECTORIZE_SUPPORT_VECTOR_MISALIGNMENT
#define TARGET_VECTORIZE_SUPPORT_VECTOR_MISALIGNMENT                           \
    default_builtin_support_vector_misalignment
#endif
#ifndef TARGET_VECTORIZE_PREFERRED_SIMD_MODE
#define TARGET_VECTORIZE_PREFERRED_SIMD_MODE default_preferred_simd_mode
#endif
#ifndef TARGET_VECTORIZE_SPLIT_REDUCTION
#define TARGET_VECTORIZE_SPLIT_REDUCTION default_split_reduction
#endif
#ifndef TARGET_VECTORIZE_AUTOVECTORIZE_VECTOR_SIZES
#define TARGET_VECTORIZE_AUTOVECTORIZE_VECTOR_SIZES                            \
    default_autovectorize_vector_sizes
#endif
#ifndef TARGET_VECTORIZE_GET_MASK_MODE
#define TARGET_VECTORIZE_GET_MASK_MODE default_get_mask_mode
#endif
#ifndef TARGET_VECTORIZE_EMPTY_MASK_IS_EXPENSIVE
#define TARGET_VECTORIZE_EMPTY_MASK_IS_EXPENSIVE default_empty_mask_is_expensive
#endif
#ifndef TARGET_VECTORIZE_BUILTIN_GATHER
#define TARGET_VECTORIZE_BUILTIN_GATHER NULL
#endif
#ifndef TARGET_VECTORIZE_BUILTIN_SCATTER
#define TARGET_VECTORIZE_BUILTIN_SCATTER NULL
#endif
#ifndef TARGET_VECTORIZE_INIT_COST
#define TARGET_VECTORIZE_INIT_COST default_init_cost
#endif
#ifndef TARGET_VECTORIZE_ADD_STMT_COST
#define TARGET_VECTORIZE_ADD_STMT_COST default_add_stmt_cost
#endif
#ifndef TARGET_VECTORIZE_FINISH_COST
#define TARGET_VECTORIZE_FINISH_COST default_finish_cost
#endif
#ifndef TARGET_VECTORIZE_DESTROY_COST_DATA
#define TARGET_VECTORIZE_DESTROY_COST_DATA default_destroy_cost_data
#endif
#ifndef TARGET_PREFERRED_ELSE_VALUE
#define TARGET_PREFERRED_ELSE_VALUE default_preferred_else_value
#endif
#ifndef TARGET_RECORD_OFFLOAD_SYMBOL
#define TARGET_RECORD_OFFLOAD_SYMBOL hook_void_tree
#endif
#ifndef TARGET_ABSOLUTE_BIGGEST_ALIGNMENT
#define TARGET_ABSOLUTE_BIGGEST_ALIGNMENT BIGGEST_ALIGNMENT
#endif
#ifndef TARGET_OVERRIDE_OPTIONS_AFTER_CHANGE
#define TARGET_OVERRIDE_OPTIONS_AFTER_CHANGE hook_void_void
#endif
#ifndef TARGET_OFFLOAD_OPTIONS
#define TARGET_OFFLOAD_OPTIONS hook_charptr_void_null
#endif
#ifndef TARGET_EH_RETURN_FILTER_MODE
#define TARGET_EH_RETURN_FILTER_MODE default_eh_return_filter_mode
#endif
#ifndef TARGET_LIBGCC_CMP_RETURN_MODE
#define TARGET_LIBGCC_CMP_RETURN_MODE default_libgcc_cmp_return_mode
#endif
#ifndef TARGET_LIBGCC_SHIFT_COUNT_MODE
#define TARGET_LIBGCC_SHIFT_COUNT_MODE default_libgcc_shift_count_mode
#endif
#ifndef TARGET_UNWIND_WORD_MODE
#define TARGET_UNWIND_WORD_MODE default_unwind_word_mode
#endif
#ifndef TARGET_MERGE_DECL_ATTRIBUTES
#define TARGET_MERGE_DECL_ATTRIBUTES merge_decl_attributes
#endif
#ifndef TARGET_MERGE_TYPE_ATTRIBUTES
#define TARGET_MERGE_TYPE_ATTRIBUTES merge_type_attributes
#endif
#ifndef TARGET_ATTRIBUTE_TABLE
#define TARGET_ATTRIBUTE_TABLE NULL
#endif
#ifndef TARGET_ATTRIBUTE_TAKES_IDENTIFIER_P
#define TARGET_ATTRIBUTE_TAKES_IDENTIFIER_P hook_bool_const_tree_false
#endif
#ifndef TARGET_COMP_TYPE_ATTRIBUTES
#define TARGET_COMP_TYPE_ATTRIBUTES hook_int_const_tree_const_tree_1
#endif
#ifndef TARGET_SET_DEFAULT_TYPE_ATTRIBUTES
#define TARGET_SET_DEFAULT_TYPE_ATTRIBUTES hook_void_tree
#endif
#ifndef TARGET_INSERT_ATTRIBUTES
#define TARGET_INSERT_ATTRIBUTES hook_void_tree_treeptr
#endif
#ifndef TARGET_FUNCTION_ATTRIBUTE_INLINABLE_P
#define TARGET_FUNCTION_ATTRIBUTE_INLINABLE_P hook_bool_const_tree_false
#endif
#ifndef TARGET_MS_BITFIELD_LAYOUT_P
#define TARGET_MS_BITFIELD_LAYOUT_P hook_bool_const_tree_false
#endif
#ifndef TARGET_WORDS_BIG_ENDIAN
#define TARGET_WORDS_BIG_ENDIAN targhook_words_big_endian
#endif
#ifndef TARGET_FLOAT_WORDS_BIG_ENDIAN
#define TARGET_FLOAT_WORDS_BIG_ENDIAN targhook_float_words_big_endian
#endif
#ifndef TARGET_FLOAT_EXCEPTIONS_ROUNDING_SUPPORTED_P
#define TARGET_FLOAT_EXCEPTIONS_ROUNDING_SUPPORTED_P                           \
    default_float_exceptions_rounding_supported_p
#endif
#ifndef TARGET_DECIMAL_FLOAT_SUPPORTED_P
#define TARGET_DECIMAL_FLOAT_SUPPORTED_P default_decimal_float_supported_p
#endif
#ifndef TARGET_FIXED_POINT_SUPPORTED_P
#define TARGET_FIXED_POINT_SUPPORTED_P default_fixed_point_supported_p
#endif
#ifndef TARGET_ALIGN_ANON_BITFIELD
#define TARGET_ALIGN_ANON_BITFIELD hook_bool_void_false
#endif
#ifndef TARGET_NARROW_VOLATILE_BITFIELD
#define TARGET_NARROW_VOLATILE_BITFIELD hook_bool_void_false
#endif
#ifndef TARGET_INIT_BUILTINS
#define TARGET_INIT_BUILTINS hook_void_void
#endif
#ifndef TARGET_BUILTIN_DECL
#define TARGET_BUILTIN_DECL NULL
#endif
#ifndef TARGET_EXPAND_BUILTIN
#define TARGET_EXPAND_BUILTIN default_expand_builtin
#endif
#ifndef TARGET_RESOLVE_OVERLOADED_BUILTIN
#define TARGET_RESOLVE_OVERLOADED_BUILTIN NULL
#endif
#ifndef TARGET_FOLD_BUILTIN
#define TARGET_FOLD_BUILTIN hook_tree_tree_int_treep_bool_null
#endif
#ifndef TARGET_GIMPLE_FOLD_BUILTIN
#define TARGET_GIMPLE_FOLD_BUILTIN hook_bool_gsiptr_false
#endif
#ifndef TARGET_COMPARE_VERSION_PRIORITY
#define TARGET_COMPARE_VERSION_PRIORITY NULL
#endif
#ifndef TARGET_GENERATE_VERSION_DISPATCHER_BODY
#define TARGET_GENERATE_VERSION_DISPATCHER_BODY NULL
#endif
#ifndef TARGET_GET_FUNCTION_VERSIONS_DISPATCHER
#define TARGET_GET_FUNCTION_VERSIONS_DISPATCHER NULL
#endif
#ifndef TARGET_BUILTIN_RECIPROCAL
#define TARGET_BUILTIN_RECIPROCAL default_builtin_reciprocal
#endif
#ifndef TARGET_MANGLE_TYPE
#define TARGET_MANGLE_TYPE hook_constcharptr_const_tree_null
#endif
#ifndef TARGET_INIT_LIBFUNCS
#define TARGET_INIT_LIBFUNCS hook_void_void
#endif
#ifndef TARGET_LIBFUNC_GNU_PREFIX
#define TARGET_LIBFUNC_GNU_PREFIX false
#endif
#ifndef TARGET_SECTION_TYPE_FLAGS
#define TARGET_SECTION_TYPE_FLAGS default_section_type_flags
#endif
#ifndef TARGET_LIBC_HAS_FUNCTION
#define TARGET_LIBC_HAS_FUNCTION default_libc_has_function
#endif
#ifndef TARGET_CANNOT_MODIFY_JUMPS_P
#define TARGET_CANNOT_MODIFY_JUMPS_P hook_bool_void_false
#endif
#ifndef TARGET_CAN_FOLLOW_JUMP
#define TARGET_CAN_FOLLOW_JUMP hook_bool_const_rtx_insn_const_rtx_insn_true
#endif
#ifndef TARGET_BRANCH_TARGET_REGISTER_CLASS
#define TARGET_BRANCH_TARGET_REGISTER_CLASS default_branch_target_register_class
#endif
#ifndef TARGET_BRANCH_TARGET_REGISTER_CALLEE_SAVED
#define TARGET_BRANCH_TARGET_REGISTER_CALLEE_SAVED hook_bool_bool_false
#endif
#ifndef TARGET_HAVE_CONDITIONAL_EXECUTION
#define TARGET_HAVE_CONDITIONAL_EXECUTION default_have_conditional_execution
#endif
#ifndef TARGET_GEN_CCMP_FIRST
#define TARGET_GEN_CCMP_FIRST NULL
#endif
#ifndef TARGET_GEN_CCMP_NEXT
#define TARGET_GEN_CCMP_NEXT NULL
#endif
#ifndef TARGET_LOOP_UNROLL_ADJUST
#define TARGET_LOOP_UNROLL_ADJUST NULL
#endif
#ifndef TARGET_LEGITIMATE_CONSTANT_P
#define TARGET_LEGITIMATE_CONSTANT_P hook_bool_mode_rtx_true
#endif
#ifndef TARGET_CANNOT_FORCE_CONST_MEM
#define TARGET_CANNOT_FORCE_CONST_MEM hook_bool_mode_rtx_false
#endif
#ifndef TARGET_CANNOT_COPY_INSN_P
#define TARGET_CANNOT_COPY_INSN_P NULL
#endif
#ifndef TARGET_COMMUTATIVE_P
#define TARGET_COMMUTATIVE_P hook_bool_const_rtx_commutative_p
#endif
#ifndef TARGET_MODE_DEPENDENT_ADDRESS_P
#define TARGET_MODE_DEPENDENT_ADDRESS_P default_mode_dependent_address_p
#endif
#ifndef TARGET_LEGITIMIZE_ADDRESS
#define TARGET_LEGITIMIZE_ADDRESS default_legitimize_address
#endif
#ifndef TARGET_DELEGITIMIZE_ADDRESS
#define TARGET_DELEGITIMIZE_ADDRESS delegitimize_mem_from_attrs
#endif
#ifndef TARGET_CONST_NOT_OK_FOR_DEBUG_P
#define TARGET_CONST_NOT_OK_FOR_DEBUG_P default_const_not_ok_for_debug_p
#endif
#ifndef TARGET_LEGITIMATE_ADDRESS_P
#define TARGET_LEGITIMATE_ADDRESS_P default_legitimate_address_p
#endif
#ifndef TARGET_USE_BLOCKS_FOR_CONSTANT_P
#define TARGET_USE_BLOCKS_FOR_CONSTANT_P hook_bool_mode_const_rtx_false
#endif
#ifndef TARGET_USE_BLOCKS_FOR_DECL_P
#define TARGET_USE_BLOCKS_FOR_DECL_P hook_bool_const_tree_true
#endif
#ifndef TARGET_MIN_ANCHOR_OFFSET
#define TARGET_MIN_ANCHOR_OFFSET 0
#endif
#ifndef TARGET_MAX_ANCHOR_OFFSET
#define TARGET_MAX_ANCHOR_OFFSET 0
#endif
#ifndef TARGET_USE_ANCHORS_FOR_SYMBOL_P
#define TARGET_USE_ANCHORS_FOR_SYMBOL_P default_use_anchors_for_symbol_p
#endif
#ifndef TARGET_HAS_IFUNC_P
#define TARGET_HAS_IFUNC_P default_has_ifunc_p
#endif
#ifndef TARGET_FUNCTION_OK_FOR_SIBCALL
#define TARGET_FUNCTION_OK_FOR_SIBCALL hook_bool_tree_tree_false
#endif
#ifndef TARGET_SET_CURRENT_FUNCTION
#define TARGET_SET_CURRENT_FUNCTION hook_void_tree
#endif
#ifndef TARGET_IN_SMALL_DATA_P
#define TARGET_IN_SMALL_DATA_P hook_bool_const_tree_false
#endif
#ifndef TARGET_BINDS_LOCAL_P
#define TARGET_BINDS_LOCAL_P default_binds_local_p
#endif
#ifndef TARGET_PROFILE_BEFORE_PROLOGUE
#define TARGET_PROFILE_BEFORE_PROLOGUE default_profile_before_prologue
#endif
#ifndef TARGET_KEEP_LEAF_WHEN_PROFILED
#define TARGET_KEEP_LEAF_WHEN_PROFILED default_keep_leaf_when_profiled
#endif
#ifndef TARGET_MANGLE_DECL_ASSEMBLER_NAME
#define TARGET_MANGLE_DECL_ASSEMBLER_NAME default_mangle_decl_assembler_name
#endif
#ifndef TARGET_ENCODE_SECTION_INFO
#define TARGET_ENCODE_SECTION_INFO default_encode_section_info
#endif
#ifndef TARGET_STRIP_NAME_ENCODING
#define TARGET_STRIP_NAME_ENCODING default_strip_name_encoding
#endif
#ifndef TARGET_SHIFT_TRUNCATION_MASK
#define TARGET_SHIFT_TRUNCATION_MASK default_shift_truncation_mask
#endif
#ifndef TARGET_MIN_DIVISIONS_FOR_RECIP_MUL
#define TARGET_MIN_DIVISIONS_FOR_RECIP_MUL default_min_divisions_for_recip_mul
#endif
#ifndef TARGET_TRULY_NOOP_TRUNCATION
#define TARGET_TRULY_NOOP_TRUNCATION hook_bool_puint64_puint64_true
#endif
#ifndef TARGET_MODE_REP_EXTENDED
#define TARGET_MODE_REP_EXTENDED default_mode_rep_extended
#endif
#ifndef TARGET_SETJMP_PRESERVES_NONVOLATILE_REGS_P
#define TARGET_SETJMP_PRESERVES_NONVOLATILE_REGS_P hook_bool_void_false
#endif
#ifndef TARGET_VALID_POINTER_MODE
#define TARGET_VALID_POINTER_MODE default_valid_pointer_mode
#endif
#ifndef TARGET_REF_MAY_ALIAS_ERRNO
#define TARGET_REF_MAY_ALIAS_ERRNO default_ref_may_alias_errno
#endif
#ifndef TARGET_ADDR_SPACE_POINTER_MODE
#define TARGET_ADDR_SPACE_POINTER_MODE default_addr_space_pointer_mode
#endif
#ifndef TARGET_ADDR_SPACE_ADDRESS_MODE
#define TARGET_ADDR_SPACE_ADDRESS_MODE default_addr_space_address_mode
#endif
#ifndef TARGET_ADDR_SPACE_VALID_POINTER_MODE
#define TARGET_ADDR_SPACE_VALID_POINTER_MODE                                   \
    default_addr_space_valid_pointer_mode
#endif
#ifndef TARGET_ADDR_SPACE_LEGITIMATE_ADDRESS_P
#define TARGET_ADDR_SPACE_LEGITIMATE_ADDRESS_P                                 \
    default_addr_space_legitimate_address_p
#endif
#ifndef TARGET_ADDR_SPACE_LEGITIMIZE_ADDRESS
#define TARGET_ADDR_SPACE_LEGITIMIZE_ADDRESS                                   \
    default_addr_space_legitimize_address
#endif
#ifndef TARGET_ADDR_SPACE_SUBSET_P
#define TARGET_ADDR_SPACE_SUBSET_P default_addr_space_subset_p
#endif
#ifndef TARGET_ADDR_SPACE_ZERO_ADDRESS_VALID
#define TARGET_ADDR_SPACE_ZERO_ADDRESS_VALID                                   \
    default_addr_space_zero_address_valid
#endif
#ifndef TARGET_ADDR_SPACE_CONVERT
#define TARGET_ADDR_SPACE_CONVERT default_addr_space_convert
#endif
#ifndef TARGET_ADDR_SPACE_DEBUG
#define TARGET_ADDR_SPACE_DEBUG default_addr_space_debug
#endif
#ifndef TARGET_ADDR_SPACE_DIAGNOSE_USAGE
#define TARGET_ADDR_SPACE_DIAGNOSE_USAGE default_addr_space_diagnose_usage
#endif
#ifndef TARGET_STATIC_RTX_ALIGNMENT
#define TARGET_STATIC_RTX_ALIGNMENT default_static_rtx_alignment
#endif
#ifndef TARGET_CONSTANT_ALIGNMENT
#define TARGET_CONSTANT_ALIGNMENT default_constant_alignment
#endif
#ifndef TARGET_TRANSLATE_MODE_ATTRIBUTE
#define TARGET_TRANSLATE_MODE_ATTRIBUTE default_translate_mode_attribute
#endif
#ifndef TARGET_SCALAR_MODE_SUPPORTED_P
#define TARGET_SCALAR_MODE_SUPPORTED_P default_scalar_mode_supported_p
#endif
#ifndef TARGET_VECTOR_MODE_SUPPORTED_P
#define TARGET_VECTOR_MODE_SUPPORTED_P hook_bool_mode_false
#endif
#ifndef TARGET_VECTOR_ALIGNMENT
#define TARGET_VECTOR_ALIGNMENT default_vector_alignment
#endif
#ifndef TARGET_ARRAY_MODE
#define TARGET_ARRAY_MODE hook_optmode_mode_uhwi_none
#endif
#ifndef TARGET_ARRAY_MODE_SUPPORTED_P
#define TARGET_ARRAY_MODE_SUPPORTED_P hook_bool_mode_uhwi_false
#endif
#ifndef TARGET_LIBGCC_FLOATING_MODE_SUPPORTED_P
#define TARGET_LIBGCC_FLOATING_MODE_SUPPORTED_P                                \
    default_libgcc_floating_mode_supported_p
#endif
#ifndef TARGET_FLOATN_MODE
#define TARGET_FLOATN_MODE default_floatn_mode
#endif
#ifndef TARGET_FLOATN_BUILTIN_P
#define TARGET_FLOATN_BUILTIN_P default_floatn_builtin_p
#endif
#ifndef TARGET_REGISTER_MOVE_COST
#define TARGET_REGISTER_MOVE_COST default_register_move_cost
#endif
#ifndef TARGET_MEMORY_MOVE_COST
#define TARGET_MEMORY_MOVE_COST default_memory_move_cost
#endif
#ifndef TARGET_USE_BY_PIECES_INFRASTRUCTURE_P
#define TARGET_USE_BY_PIECES_INFRASTRUCTURE_P                                  \
    default_use_by_pieces_infrastructure_p
#endif
#ifndef TARGET_COMPARE_BY_PIECES_BRANCH_RATIO
#define TARGET_COMPARE_BY_PIECES_BRANCH_RATIO                                  \
    default_compare_by_pieces_branch_ratio
#endif
#ifndef TARGET_SLOW_UNALIGNED_ACCESS
#define TARGET_SLOW_UNALIGNED_ACCESS default_slow_unaligned_access
#endif
#ifndef TARGET_OPTAB_SUPPORTED_P
#define TARGET_OPTAB_SUPPORTED_P default_optab_supported_p
#endif
#ifndef TARGET_SMALL_REGISTER_CLASSES_FOR_MODE_P
#define TARGET_SMALL_REGISTER_CLASSES_FOR_MODE_P hook_bool_mode_false
#endif
#ifndef TARGET_FLAGS_REGNUM
#define TARGET_FLAGS_REGNUM INVALID_REGNUM
#endif
#ifndef TARGET_RTX_COSTS
#define TARGET_RTX_COSTS hook_bool_rtx_mode_int_int_intp_bool_false
#endif
#ifndef TARGET_ADDRESS_COST
#define TARGET_ADDRESS_COST default_address_cost
#endif
#ifndef TARGET_INSN_COST
#define TARGET_INSN_COST NULL
#endif
#ifndef TARGET_MAX_NOCE_IFCVT_SEQ_COST
#define TARGET_MAX_NOCE_IFCVT_SEQ_COST default_max_noce_ifcvt_seq_cost
#endif
#ifndef TARGET_NOCE_CONVERSION_PROFITABLE_P
#define TARGET_NOCE_CONVERSION_PROFITABLE_P default_noce_conversion_profitable_p
#endif
#ifndef TARGET_ESTIMATED_POLY_VALUE
#define TARGET_ESTIMATED_POLY_VALUE default_estimated_poly_value
#endif
#ifndef TARGET_NO_SPECULATION_IN_DELAY_SLOTS_P
#define TARGET_NO_SPECULATION_IN_DELAY_SLOTS_P hook_bool_void_false
#endif
#ifndef TARGET_ALLOCATE_INITIAL_VALUE
#define TARGET_ALLOCATE_INITIAL_VALUE NULL
#endif
#ifndef TARGET_UNSPEC_MAY_TRAP_P
#define TARGET_UNSPEC_MAY_TRAP_P default_unspec_may_trap_p
#endif
#ifndef TARGET_DWARF_REGISTER_SPAN
#define TARGET_DWARF_REGISTER_SPAN hook_rtx_rtx_null
#endif
#ifndef TARGET_DWARF_FRAME_REG_MODE
#define TARGET_DWARF_FRAME_REG_MODE default_dwarf_frame_reg_mode
#endif
#ifndef TARGET_INIT_DWARF_REG_SIZES_EXTRA
#define TARGET_INIT_DWARF_REG_SIZES_EXTRA hook_void_tree
#endif
#ifndef TARGET_FIXED_CONDITION_CODE_REGS
#define TARGET_FIXED_CONDITION_CODE_REGS hook_bool_uintp_uintp_false
#endif
#ifndef TARGET_CC_MODES_COMPATIBLE
#define TARGET_CC_MODES_COMPATIBLE default_cc_modes_compatible
#endif
#ifndef TARGET_MACHINE_DEPENDENT_REORG
#define TARGET_MACHINE_DEPENDENT_REORG NULL
#endif
#ifndef TARGET_BUILD_BUILTIN_VA_LIST
#define TARGET_BUILD_BUILTIN_VA_LIST std_build_builtin_va_list
#endif
#ifndef TARGET_ENUM_VA_LIST_P
#define TARGET_ENUM_VA_LIST_P NULL
#endif
#ifndef TARGET_FN_ABI_VA_LIST
#define TARGET_FN_ABI_VA_LIST std_fn_abi_va_list
#endif
#ifndef TARGET_CANONICAL_VA_LIST_TYPE
#define TARGET_CANONICAL_VA_LIST_TYPE std_canonical_va_list_type
#endif
#ifndef TARGET_EXPAND_BUILTIN_VA_START
#define TARGET_EXPAND_BUILTIN_VA_START NULL
#endif
#ifndef TARGET_GIMPLIFY_VA_ARG_EXPR
#define TARGET_GIMPLIFY_VA_ARG_EXPR std_gimplify_va_arg_expr
#endif
#ifndef TARGET_GET_PCH_VALIDITY
#define TARGET_GET_PCH_VALIDITY default_get_pch_validity
#endif
#ifndef TARGET_PCH_VALID_P
#define TARGET_PCH_VALID_P default_pch_valid_p
#endif
#ifndef TARGET_PREPARE_PCH_SAVE
#define TARGET_PREPARE_PCH_SAVE hook_void_void
#endif
#ifndef TARGET_CHECK_PCH_TARGET_FLAGS
#define TARGET_CHECK_PCH_TARGET_FLAGS NULL
#endif
#ifndef TARGET_DEFAULT_SHORT_ENUMS
#define TARGET_DEFAULT_SHORT_ENUMS hook_bool_void_false
#endif
#ifndef TARGET_BUILTIN_SETJMP_FRAME_VALUE
#define TARGET_BUILTIN_SETJMP_FRAME_VALUE default_builtin_setjmp_frame_value
#endif
#ifndef TARGET_MD_ASM_ADJUST
#define TARGET_MD_ASM_ADJUST NULL
#endif
#ifndef TARGET_DWARF_CALLING_CONVENTION
#define TARGET_DWARF_CALLING_CONVENTION hook_int_const_tree_0
#endif
#ifndef TARGET_DWARF_HANDLE_FRAME_UNSPEC
#define TARGET_DWARF_HANDLE_FRAME_UNSPEC NULL
#endif
#ifndef TARGET_DWARF_POLY_INDETERMINATE_VALUE
#define TARGET_DWARF_POLY_INDETERMINATE_VALUE                                  \
    default_dwarf_poly_indeterminate_value
#endif
#ifndef TARGET_STDARG_OPTIMIZE_HOOK
#define TARGET_STDARG_OPTIMIZE_HOOK NULL
#endif
#ifndef TARGET_STACK_PROTECT_GUARD
#define TARGET_STACK_PROTECT_GUARD default_stack_protect_guard
#endif
#ifndef TARGET_STACK_PROTECT_FAIL
#define TARGET_STACK_PROTECT_FAIL default_external_stack_protect_fail
#endif
#ifndef TARGET_STACK_PROTECT_RUNTIME_ENABLED_P
#define TARGET_STACK_PROTECT_RUNTIME_ENABLED_P hook_bool_void_true
#endif
#ifndef TARGET_HAVE_SPECULATION_SAFE_VALUE
#define TARGET_HAVE_SPECULATION_SAFE_VALUE default_have_speculation_safe_value
#endif
#ifndef TARGET_SPECULATION_SAFE_VALUE
#define TARGET_SPECULATION_SAFE_VALUE default_speculation_safe_value
#endif
#ifndef TARGET_CAN_USE_DOLOOP_P
#define TARGET_CAN_USE_DOLOOP_P hook_bool_wint_wint_uint_bool_true
#endif
#ifndef TARGET_INVALID_WITHIN_DOLOOP
#define TARGET_INVALID_WITHIN_DOLOOP default_invalid_within_doloop
#endif
#ifndef TARGET_LEGITIMATE_COMBINED_INSN
#define TARGET_LEGITIMATE_COMBINED_INSN hook_bool_rtx_insn_true
#endif
#ifndef TARGET_VALID_DLLIMPORT_ATTRIBUTE_P
#define TARGET_VALID_DLLIMPORT_ATTRIBUTE_P hook_bool_const_tree_true
#endif
#ifndef TARGET_CONST_ANCHOR
#define TARGET_CONST_ANCHOR 0
#endif
#ifndef TARGET_MEMMODEL_CHECK
#define TARGET_MEMMODEL_CHECK NULL
#endif
#ifndef TARGET_ASAN_SHADOW_OFFSET
#define TARGET_ASAN_SHADOW_OFFSET NULL
#endif
#ifndef TARGET_PROMOTE_FUNCTION_MODE
#define TARGET_PROMOTE_FUNCTION_MODE default_promote_function_mode
#endif
#ifndef TARGET_PROMOTE_PROTOTYPES
#define TARGET_PROMOTE_PROTOTYPES hook_bool_const_tree_false
#endif
#ifndef TARGET_STRUCT_VALUE_RTX
#define TARGET_STRUCT_VALUE_RTX hook_rtx_tree_int_null
#endif
#ifndef TARGET_OMIT_STRUCT_RETURN_REG
#define TARGET_OMIT_STRUCT_RETURN_REG false
#endif
#ifndef TARGET_RETURN_IN_MEMORY
#define TARGET_RETURN_IN_MEMORY default_return_in_memory
#endif
#ifndef TARGET_RETURN_IN_MSB
#define TARGET_RETURN_IN_MSB hook_bool_const_tree_false
#endif
#ifndef TARGET_PASS_BY_REFERENCE
#define TARGET_PASS_BY_REFERENCE hook_bool_CUMULATIVE_ARGS_mode_tree_bool_false
#endif
#ifndef TARGET_EXPAND_BUILTIN_SAVEREGS
#define TARGET_EXPAND_BUILTIN_SAVEREGS default_expand_builtin_saveregs
#endif
#ifndef TARGET_SETUP_INCOMING_VARARGS
#define TARGET_SETUP_INCOMING_VARARGS default_setup_incoming_varargs
#endif
#ifndef TARGET_LOAD_BOUNDS_FOR_ARG
#define TARGET_LOAD_BOUNDS_FOR_ARG default_load_bounds_for_arg
#endif
#ifndef TARGET_STORE_BOUNDS_FOR_ARG
#define TARGET_STORE_BOUNDS_FOR_ARG default_store_bounds_for_arg
#endif
#ifndef TARGET_LOAD_RETURNED_BOUNDS
#define TARGET_LOAD_RETURNED_BOUNDS default_load_returned_bounds
#endif
#ifndef TARGET_STORE_RETURNED_BOUNDS
#define TARGET_STORE_RETURNED_BOUNDS default_store_returned_bounds
#endif
#ifndef TARGET_SETUP_INCOMING_VARARG_BOUNDS
#define TARGET_SETUP_INCOMING_VARARG_BOUNDS default_setup_incoming_vararg_bounds
#endif
#ifndef TARGET_CALL_ARGS
#define TARGET_CALL_ARGS hook_void_rtx_tree
#endif
#ifndef TARGET_END_CALL_ARGS
#define TARGET_END_CALL_ARGS hook_void_void
#endif
#ifndef TARGET_STRICT_ARGUMENT_NAMING
#define TARGET_STRICT_ARGUMENT_NAMING hook_bool_CUMULATIVE_ARGS_false
#endif
#ifndef TARGET_PRETEND_OUTGOING_VARARGS_NAMED
#define TARGET_PRETEND_OUTGOING_VARARGS_NAMED                                  \
    default_pretend_outgoing_varargs_named
#endif
#ifndef TARGET_SPLIT_COMPLEX_ARG
#define TARGET_SPLIT_COMPLEX_ARG NULL
#endif
#ifndef TARGET_MUST_PASS_IN_STACK
#define TARGET_MUST_PASS_IN_STACK must_pass_in_stack_var_size_or_pad
#endif
#ifndef TARGET_CALLEE_COPIES
#define TARGET_CALLEE_COPIES hook_bool_CUMULATIVE_ARGS_mode_tree_bool_false
#endif
#ifndef TARGET_ARG_PARTIAL_BYTES
#define TARGET_ARG_PARTIAL_BYTES hook_int_CUMULATIVE_ARGS_mode_tree_bool_0
#endif
#ifndef TARGET_FUNCTION_ARG_ADVANCE
#define TARGET_FUNCTION_ARG_ADVANCE default_function_arg_advance
#endif
#ifndef TARGET_FUNCTION_ARG_OFFSET
#define TARGET_FUNCTION_ARG_OFFSET default_function_arg_offset
#endif
#ifndef TARGET_FUNCTION_ARG_PADDING
#define TARGET_FUNCTION_ARG_PADDING default_function_arg_padding
#endif
#ifndef TARGET_FUNCTION_ARG
#define TARGET_FUNCTION_ARG default_function_arg
#endif
#ifndef TARGET_FUNCTION_INCOMING_ARG
#define TARGET_FUNCTION_INCOMING_ARG default_function_incoming_arg
#endif
#ifndef TARGET_FUNCTION_ARG_BOUNDARY
#define TARGET_FUNCTION_ARG_BOUNDARY default_function_arg_boundary
#endif
#ifndef TARGET_FUNCTION_ARG_ROUND_BOUNDARY
#define TARGET_FUNCTION_ARG_ROUND_BOUNDARY default_function_arg_round_boundary
#endif
#ifndef TARGET_INVALID_ARG_FOR_UNPROTOTYPED_FN
#define TARGET_INVALID_ARG_FOR_UNPROTOTYPED_FN                                 \
    hook_invalid_arg_for_unprototyped_fn
#endif
#ifndef TARGET_FUNCTION_VALUE
#define TARGET_FUNCTION_VALUE default_function_value
#endif
#ifndef TARGET_LIBCALL_VALUE
#define TARGET_LIBCALL_VALUE default_libcall_value
#endif
#ifndef TARGET_FUNCTION_VALUE_REGNO_P
#define TARGET_FUNCTION_VALUE_REGNO_P default_function_value_regno_p
#endif
#ifndef TARGET_INTERNAL_ARG_POINTER
#define TARGET_INTERNAL_ARG_POINTER default_internal_arg_pointer
#endif
#ifndef TARGET_UPDATE_STACK_BOUNDARY
#define TARGET_UPDATE_STACK_BOUNDARY NULL
#endif
#ifndef TARGET_GET_DRAP_RTX
#define TARGET_GET_DRAP_RTX NULL
#endif
#ifndef TARGET_ALLOCATE_STACK_SLOTS_FOR_ARGS
#define TARGET_ALLOCATE_STACK_SLOTS_FOR_ARGS hook_bool_void_true
#endif
#ifndef TARGET_STATIC_CHAIN
#define TARGET_STATIC_CHAIN default_static_chain
#endif
#ifndef TARGET_TRAMPOLINE_INIT
#define TARGET_TRAMPOLINE_INIT default_trampoline_init
#endif
#ifndef TARGET_TRAMPOLINE_ADJUST_ADDRESS
#define TARGET_TRAMPOLINE_ADJUST_ADDRESS NULL
#endif
#ifndef TARGET_CUSTOM_FUNCTION_DESCRIPTORS
#define TARGET_CUSTOM_FUNCTION_DESCRIPTORS -1
#endif
#ifndef TARGET_RETURN_POPS_ARGS
#define TARGET_RETURN_POPS_ARGS default_return_pops_args
#endif
#ifndef TARGET_GET_RAW_RESULT_MODE
#define TARGET_GET_RAW_RESULT_MODE default_get_reg_raw_mode
#endif
#ifndef TARGET_GET_RAW_ARG_MODE
#define TARGET_GET_RAW_ARG_MODE default_get_reg_raw_mode
#endif
#ifndef TARGET_EMPTY_RECORD_P
#define TARGET_EMPTY_RECORD_P hook_bool_const_tree_false
#endif
#ifndef TARGET_WARN_PARAMETER_PASSING_ABI
#define TARGET_WARN_PARAMETER_PASSING_ABI hook_void_CUMULATIVE_ARGS_tree
#endif
#ifndef TARGET_USE_PSEUDO_PIC_REG
#define TARGET_USE_PSEUDO_PIC_REG hook_bool_void_false
#endif
#ifndef TARGET_INIT_PIC_REG
#define TARGET_INIT_PIC_REG hook_void_void
#endif
#ifndef TARGET_INVALID_CONVERSION
#define TARGET_INVALID_CONVERSION hook_constcharptr_const_tree_const_tree_null
#endif
#ifndef TARGET_INVALID_UNARY_OP
#define TARGET_INVALID_UNARY_OP hook_constcharptr_int_const_tree_null
#endif
#ifndef TARGET_INVALID_BINARY_OP
#define TARGET_INVALID_BINARY_OP                                               \
    hook_constcharptr_int_const_tree_const_tree_null
#endif
#ifndef TARGET_PROMOTED_TYPE
#define TARGET_PROMOTED_TYPE hook_tree_const_tree_null
#endif
#ifndef TARGET_CONVERT_TO_TYPE
#define TARGET_CONVERT_TO_TYPE hook_tree_tree_tree_null
#endif
#ifndef TARGET_CAN_CHANGE_MODE_CLASS
#define TARGET_CAN_CHANGE_MODE_CLASS hook_bool_mode_mode_reg_class_t_true
#endif
#ifndef TARGET_IRA_CHANGE_PSEUDO_ALLOCNO_CLASS
#define TARGET_IRA_CHANGE_PSEUDO_ALLOCNO_CLASS                                 \
    default_ira_change_pseudo_allocno_class
#endif
#ifndef TARGET_LRA_P
#define TARGET_LRA_P default_lra_p
#endif
#ifndef TARGET_REGISTER_PRIORITY
#define TARGET_REGISTER_PRIORITY default_register_priority
#endif
#ifndef TARGET_REGISTER_USAGE_LEVELING_P
#define TARGET_REGISTER_USAGE_LEVELING_P default_register_usage_leveling_p
#endif
#ifndef TARGET_DIFFERENT_ADDR_DISPLACEMENT_P
#define TARGET_DIFFERENT_ADDR_DISPLACEMENT_P                                   \
    default_different_addr_displacement_p
#endif
#ifndef TARGET_SPILL_CLASS
#define TARGET_SPILL_CLASS NULL
#endif
#ifndef TARGET_ADDITIONAL_ALLOCNO_CLASS_P
#define TARGET_ADDITIONAL_ALLOCNO_CLASS_P hook_bool_reg_class_t_false
#endif
#ifndef TARGET_CSTORE_MODE
#define TARGET_CSTORE_MODE default_cstore_mode
#endif
#ifndef TARGET_COMPUTE_PRESSURE_CLASSES
#define TARGET_COMPUTE_PRESSURE_CLASSES NULL
#endif
#ifndef TARGET_MEMBER_TYPE_FORCES_BLK
#define TARGET_MEMBER_TYPE_FORCES_BLK default_member_type_forces_blk
#endif
#ifndef TARGET_EXPAND_DIVMOD_LIBFUNC
#define TARGET_EXPAND_DIVMOD_LIBFUNC NULL
#endif
#ifndef TARGET_SECONDARY_RELOAD
#define TARGET_SECONDARY_RELOAD default_secondary_reload
#endif
#ifndef TARGET_SECONDARY_MEMORY_NEEDED
#define TARGET_SECONDARY_MEMORY_NEEDED                                         \
    hook_bool_mode_reg_class_t_reg_class_t_false
#endif
#ifndef TARGET_SECONDARY_MEMORY_NEEDED_MODE
#define TARGET_SECONDARY_MEMORY_NEEDED_MODE default_secondary_memory_needed_mode
#endif
#ifndef TARGET_PREFERRED_RELOAD_CLASS
#define TARGET_PREFERRED_RELOAD_CLASS default_preferred_reload_class
#endif
#ifndef TARGET_PREFERRED_OUTPUT_RELOAD_CLASS
#define TARGET_PREFERRED_OUTPUT_RELOAD_CLASS                                   \
    default_preferred_output_reload_class
#endif
#ifndef TARGET_SELECT_EARLY_REMAT_MODES
#define TARGET_SELECT_EARLY_REMAT_MODES default_select_early_remat_modes
#endif
#ifndef TARGET_CLASS_LIKELY_SPILLED_P
#define TARGET_CLASS_LIKELY_SPILLED_P default_class_likely_spilled_p
#endif
#ifndef TARGET_CLASS_MAX_NREGS
#define TARGET_CLASS_MAX_NREGS default_class_max_nregs
#endif
#ifndef TARGET_PREFERRED_RENAME_CLASS
#define TARGET_PREFERRED_RENAME_CLASS default_preferred_rename_class
#endif
#ifndef TARGET_CANNOT_SUBSTITUTE_MEM_EQUIV_P
#define TARGET_CANNOT_SUBSTITUTE_MEM_EQUIV_P hook_bool_rtx_false
#endif
#ifndef TARGET_LEGITIMIZE_ADDRESS_DISPLACEMENT
#define TARGET_LEGITIMIZE_ADDRESS_DISPLACEMENT                                 \
    default_legitimize_address_displacement
#endif
#ifndef TARGET_EXPAND_TO_RTL_HOOK
#define TARGET_EXPAND_TO_RTL_HOOK hook_void_void
#endif
#ifndef TARGET_INSTANTIATE_DECLS
#define TARGET_INSTANTIATE_DECLS hook_void_void
#endif
#ifndef TARGET_HARD_REGNO_NREGS
#define TARGET_HARD_REGNO_NREGS default_hard_regno_nregs
#endif
#ifndef TARGET_HARD_REGNO_MODE_OK
#define TARGET_HARD_REGNO_MODE_OK hook_bool_uint_mode_true
#endif
#ifndef TARGET_MODES_TIEABLE_P
#define TARGET_MODES_TIEABLE_P hook_bool_mode_mode_true
#endif
#ifndef TARGET_HARD_REGNO_SCRATCH_OK
#define TARGET_HARD_REGNO_SCRATCH_OK default_hard_regno_scratch_ok
#endif
#ifndef TARGET_HARD_REGNO_CALL_PART_CLOBBERED
#define TARGET_HARD_REGNO_CALL_PART_CLOBBERED hook_bool_insn_uint_mode_false
#endif
#ifndef TARGET_RETURN_CALL_WITH_MAX_CLOBBERS
#define TARGET_RETURN_CALL_WITH_MAX_CLOBBERS NULL
#endif
#ifndef TARGET_GET_MULTILIB_ABI_NAME
#define TARGET_GET_MULTILIB_ABI_NAME hook_constcharptr_void_null
#endif
#ifndef TARGET_REMOVE_EXTRA_CALL_PRESERVED_REGS
#define TARGET_REMOVE_EXTRA_CALL_PRESERVED_REGS                                \
    default_remove_extra_call_preserved_regs
#endif
#ifndef TARGET_CASE_VALUES_THRESHOLD
#define TARGET_CASE_VALUES_THRESHOLD default_case_values_threshold
#endif
#ifndef TARGET_STARTING_FRAME_OFFSET
#define TARGET_STARTING_FRAME_OFFSET hook_hwi_void_0
#endif
#ifndef TARGET_COMPUTE_FRAME_LAYOUT
#define TARGET_COMPUTE_FRAME_LAYOUT hook_void_void
#endif
#ifndef TARGET_FRAME_POINTER_REQUIRED
#define TARGET_FRAME_POINTER_REQUIRED hook_bool_void_false
#endif
#ifndef TARGET_CAN_ELIMINATE
#define TARGET_CAN_ELIMINATE hook_bool_const_int_const_int_true
#endif
#ifndef TARGET_CONDITIONAL_REGISTER_USAGE
#define TARGET_CONDITIONAL_REGISTER_USAGE hook_void_void
#endif
#ifndef TARGET_STACK_CLASH_PROTECTION_ALLOCA_PROBE_RANGE
#define TARGET_STACK_CLASH_PROTECTION_ALLOCA_PROBE_RANGE                       \
    default_stack_clash_protection_alloca_probe_range
#endif
#ifndef TARGET_C_MODE_FOR_SUFFIX
#define TARGET_C_MODE_FOR_SUFFIX default_mode_for_suffix
#endif
#ifndef TARGET_C_EXCESS_PRECISION
#define TARGET_C_EXCESS_PRECISION default_excess_precision
#endif
#ifndef TARGET_CXX_GUARD_TYPE
#define TARGET_CXX_GUARD_TYPE default_cxx_guard_type
#endif
#ifndef TARGET_CXX_GUARD_MASK_BIT
#define TARGET_CXX_GUARD_MASK_BIT hook_bool_void_false
#endif
#ifndef TARGET_CXX_GET_COOKIE_SIZE
#define TARGET_CXX_GET_COOKIE_SIZE default_cxx_get_cookie_size
#endif
#ifndef TARGET_CXX_COOKIE_HAS_SIZE
#define TARGET_CXX_COOKIE_HAS_SIZE hook_bool_void_false
#endif
#ifndef TARGET_CXX_IMPORT_EXPORT_CLASS
#define TARGET_CXX_IMPORT_EXPORT_CLASS NULL
#endif
#ifndef TARGET_CXX_CDTOR_RETURNS_THIS
#define TARGET_CXX_CDTOR_RETURNS_THIS hook_bool_void_false
#endif
#ifndef TARGET_CXX_KEY_METHOD_MAY_BE_INLINE
#define TARGET_CXX_KEY_METHOD_MAY_BE_INLINE hook_bool_void_true
#endif
#ifndef TARGET_CXX_DETERMINE_CLASS_DATA_VISIBILITY
#define TARGET_CXX_DETERMINE_CLASS_DATA_VISIBILITY hook_void_tree
#endif
#ifndef TARGET_CXX_CLASS_DATA_ALWAYS_COMDAT
#define TARGET_CXX_CLASS_DATA_ALWAYS_COMDAT hook_bool_void_true
#endif
#ifndef TARGET_CXX_LIBRARY_RTTI_COMDAT
#define TARGET_CXX_LIBRARY_RTTI_COMDAT hook_bool_void_true
#endif
#ifndef TARGET_CXX_USE_AEABI_ATEXIT
#define TARGET_CXX_USE_AEABI_ATEXIT hook_bool_void_false
#endif
#ifndef TARGET_CXX_USE_ATEXIT_FOR_CXA_ATEXIT
#define TARGET_CXX_USE_ATEXIT_FOR_CXA_ATEXIT hook_bool_void_false
#endif
#ifndef TARGET_CXX_ADJUST_CLASS_AT_DEFINITION
#define TARGET_CXX_ADJUST_CLASS_AT_DEFINITION hook_void_tree
#endif
#ifndef TARGET_CXX_DECL_MANGLING_CONTEXT
#define TARGET_CXX_DECL_MANGLING_CONTEXT hook_tree_const_tree_null
#endif
#ifndef TARGET_EMUTLS_GET_ADDRESS
#define TARGET_EMUTLS_GET_ADDRESS "__builtin___emutls_get_address"
#endif
#ifndef TARGET_EMUTLS_REGISTER_COMMON
#define TARGET_EMUTLS_REGISTER_COMMON "__builtin___emutls_register_common"
#endif
#ifndef TARGET_EMUTLS_VAR_SECTION
#define TARGET_EMUTLS_VAR_SECTION NULL
#endif
#ifndef TARGET_EMUTLS_TMPL_SECTION
#define TARGET_EMUTLS_TMPL_SECTION NULL
#endif
#ifndef TARGET_EMUTLS_VAR_PREFIX
#define TARGET_EMUTLS_VAR_PREFIX NULL
#endif
#ifndef TARGET_EMUTLS_TMPL_PREFIX
#define TARGET_EMUTLS_TMPL_PREFIX NULL
#endif
#ifndef TARGET_EMUTLS_VAR_FIELDS
#define TARGET_EMUTLS_VAR_FIELDS default_emutls_var_fields
#endif
#ifndef TARGET_EMUTLS_VAR_INIT
#define TARGET_EMUTLS_VAR_INIT default_emutls_var_init
#endif
#ifndef TARGET_EMUTLS_VAR_ALIGN_FIXED
#define TARGET_EMUTLS_VAR_ALIGN_FIXED false
#endif
#ifndef TARGET_EMUTLS_DEBUG_FORM_TLS_ADDRESS
#define TARGET_EMUTLS_DEBUG_FORM_TLS_ADDRESS false
#endif
#ifndef TARGET_OPTION_VALID_ATTRIBUTE_P
#define TARGET_OPTION_VALID_ATTRIBUTE_P default_target_option_valid_attribute_p
#endif
#ifndef TARGET_OPTION_SAVE
#define TARGET_OPTION_SAVE NULL
#endif
#ifndef TARGET_OPTION_RESTORE
#define TARGET_OPTION_RESTORE NULL
#endif
#ifndef TARGET_OPTION_POST_STREAM_IN
#define TARGET_OPTION_POST_STREAM_IN NULL
#endif
#ifndef TARGET_OPTION_PRINT
#define TARGET_OPTION_PRINT NULL
#endif
#ifndef TARGET_OPTION_PRAGMA_PARSE
#define TARGET_OPTION_PRAGMA_PARSE default_target_option_pragma_parse
#endif
#ifndef TARGET_OPTION_OVERRIDE
#define TARGET_OPTION_OVERRIDE hook_void_void
#endif
#ifndef TARGET_OPTION_FUNCTION_VERSIONS
#define TARGET_OPTION_FUNCTION_VERSIONS hook_bool_tree_tree_false
#endif
#ifndef TARGET_CAN_INLINE_P
#define TARGET_CAN_INLINE_P default_target_can_inline_p
#endif
#ifndef TARGET_RELAYOUT_FUNCTION
#define TARGET_RELAYOUT_FUNCTION hook_void_tree
#endif
#ifndef TARGET_EXTRA_LIVE_ON_ENTRY
#define TARGET_EXTRA_LIVE_ON_ENTRY hook_void_bitmap
#endif
#ifndef TARGET_CALL_FUSAGE_CONTAINS_NON_CALLEE_CLOBBERS
#define TARGET_CALL_FUSAGE_CONTAINS_NON_CALLEE_CLOBBERS false
#endif
#ifndef TARGET_SET_UP_BY_PROLOGUE
#define TARGET_SET_UP_BY_PROLOGUE NULL
#endif
#ifndef TARGET_WARN_FUNC_RETURN
#define TARGET_WARN_FUNC_RETURN hook_bool_tree_true
#endif
#ifndef TARGET_SHRINK_WRAP_GET_SEPARATE_COMPONENTS
#define TARGET_SHRINK_WRAP_GET_SEPARATE_COMPONENTS NULL
#endif
#ifndef TARGET_SHRINK_WRAP_COMPONENTS_FOR_BB
#define TARGET_SHRINK_WRAP_COMPONENTS_FOR_BB NULL
#endif
#ifndef TARGET_SHRINK_WRAP_DISQUALIFY_COMPONENTS
#define TARGET_SHRINK_WRAP_DISQUALIFY_COMPONENTS NULL
#endif
#ifndef TARGET_SHRINK_WRAP_EMIT_PROLOGUE_COMPONENTS
#define TARGET_SHRINK_WRAP_EMIT_PROLOGUE_COMPONENTS NULL
#endif
#ifndef TARGET_SHRINK_WRAP_EMIT_EPILOGUE_COMPONENTS
#define TARGET_SHRINK_WRAP_EMIT_EPILOGUE_COMPONENTS NULL
#endif
#ifndef TARGET_SHRINK_WRAP_SET_HANDLED_COMPONENTS
#define TARGET_SHRINK_WRAP_SET_HANDLED_COMPONENTS NULL
#endif
#ifndef TARGET_DEBUG_UNWIND_INFO
#define TARGET_DEBUG_UNWIND_INFO default_debug_unwind_info
#endif
#ifndef TARGET_RESET_LOCATION_VIEW
#define TARGET_RESET_LOCATION_VIEW NULL
#endif
#ifndef TARGET_CANONICALIZE_COMPARISON
#define TARGET_CANONICALIZE_COMPARISON default_canonicalize_comparison
#endif
#ifndef TARGET_MIN_ARITHMETIC_PRECISION
#define TARGET_MIN_ARITHMETIC_PRECISION default_min_arithmetic_precision
#endif
#ifndef TARGET_ATOMIC_TEST_AND_SET_TRUEVAL
#define TARGET_ATOMIC_TEST_AND_SET_TRUEVAL 1
#endif
#ifndef TARGET_ATOMIC_ALIGN_FOR_MODE
#define TARGET_ATOMIC_ALIGN_FOR_MODE hook_uint_mode_0
#endif
#ifndef TARGET_ATOMIC_ASSIGN_EXPAND_FENV
#define TARGET_ATOMIC_ASSIGN_EXPAND_FENV default_atomic_assign_expand_fenv
#endif
#ifndef TARGET_HAVE_SWITCHABLE_BSS_SECTIONS
#define TARGET_HAVE_SWITCHABLE_BSS_SECTIONS false
#endif
#ifndef TARGET_HAVE_CTORS_DTORS
#define TARGET_HAVE_CTORS_DTORS false
#endif
#ifndef TARGET_HAVE_TLS
#define TARGET_HAVE_TLS false
#endif
#ifndef TARGET_HAVE_SRODATA_SECTION
#define TARGET_HAVE_SRODATA_SECTION false
#endif
#ifndef TARGET_TERMINATE_DW2_EH_FRAME_INFO
#define TARGET_TERMINATE_DW2_EH_FRAME_INFO true
#endif
#ifndef TARGET_ASM_FILE_START_APP_OFF
#define TARGET_ASM_FILE_START_APP_OFF false
#endif
#ifndef TARGET_ASM_FILE_START_FILE_DIRECTIVE
#define TARGET_ASM_FILE_START_FILE_DIRECTIVE false
#endif
#ifndef TARGET_ARM_EABI_UNWINDER
#define TARGET_ARM_EABI_UNWINDER false
#endif
#ifndef TARGET_WANT_DEBUG_PUB_SECTIONS
#define TARGET_WANT_DEBUG_PUB_SECTIONS false
#endif
#ifndef TARGET_DELAY_SCHED2
#define TARGET_DELAY_SCHED2 false
#endif
#ifndef TARGET_DELAY_VARTRACK
#define TARGET_DELAY_VARTRACK false
#endif
#ifndef TARGET_NO_REGISTER_ALLOCATION
#define TARGET_NO_REGISTER_ALLOCATION false
#endif
#ifndef TARGET_MODE_EMIT
#define TARGET_MODE_EMIT NULL
#endif
#ifndef TARGET_MODE_NEEDED
#define TARGET_MODE_NEEDED NULL
#endif
#ifndef TARGET_MODE_AFTER
#define TARGET_MODE_AFTER NULL
#endif
#ifndef TARGET_MODE_ENTRY
#define TARGET_MODE_ENTRY NULL
#endif
#ifndef TARGET_MODE_EXIT
#define TARGET_MODE_EXIT NULL
#endif
#ifndef TARGET_MODE_PRIORITY
#define TARGET_MODE_PRIORITY NULL
#endif
#ifndef TARGET_HAVE_ALLOCATE_STACK
#define TARGET_HAVE_ALLOCATE_STACK false
#endif
#ifndef TARGET_HAVE_ATOMIC_TEST_AND_SET
#define TARGET_HAVE_ATOMIC_TEST_AND_SET false
#endif
#ifndef TARGET_HAVE_BUILTIN_LONGJMP
#define TARGET_HAVE_BUILTIN_LONGJMP false
#endif
#ifndef TARGET_HAVE_BUILTIN_SETJMP_RECEIVER
#define TARGET_HAVE_BUILTIN_SETJMP_RECEIVER false
#endif
#ifndef TARGET_HAVE_BUILTIN_SETJMP_SETUP
#define TARGET_HAVE_BUILTIN_SETJMP_SETUP false
#endif
#ifndef TARGET_HAVE_CANONICALIZE_FUNCPTR_FOR_COMPARE
#define TARGET_HAVE_CANONICALIZE_FUNCPTR_FOR_COMPARE false
#endif
#ifndef TARGET_HAVE_CALL
#define TARGET_HAVE_CALL false
#endif
#ifndef TARGET_HAVE_CALL_POP
#define TARGET_HAVE_CALL_POP false
#endif
#ifndef TARGET_HAVE_CALL_VALUE
#define TARGET_HAVE_CALL_VALUE false
#endif
#ifndef TARGET_HAVE_CALL_VALUE_POP
#define TARGET_HAVE_CALL_VALUE_POP false
#endif
#ifndef TARGET_HAVE_CASESI
#define TARGET_HAVE_CASESI false
#endif
#ifndef TARGET_HAVE_CHECK_STACK
#define TARGET_HAVE_CHECK_STACK false
#endif
#ifndef TARGET_HAVE_CLEAR_CACHE
#define TARGET_HAVE_CLEAR_CACHE false
#endif
#ifndef TARGET_HAVE_DOLOOP_BEGIN
#define TARGET_HAVE_DOLOOP_BEGIN false
#endif
#ifndef TARGET_HAVE_DOLOOP_END
#define TARGET_HAVE_DOLOOP_END false
#endif
#ifndef TARGET_HAVE_EH_RETURN
#define TARGET_HAVE_EH_RETURN false
#endif
#ifndef TARGET_HAVE_EPILOGUE
#define TARGET_HAVE_EPILOGUE false
#endif
#ifndef TARGET_HAVE_EXCEPTION_RECEIVER
#define TARGET_HAVE_EXCEPTION_RECEIVER false
#endif
#ifndef TARGET_HAVE_EXTV
#define TARGET_HAVE_EXTV false
#endif
#ifndef TARGET_HAVE_EXTZV
#define TARGET_HAVE_EXTZV false
#endif
#ifndef TARGET_HAVE_INDIRECT_JUMP
#define TARGET_HAVE_INDIRECT_JUMP false
#endif
#ifndef TARGET_HAVE_INSV
#define TARGET_HAVE_INSV false
#endif
#ifndef TARGET_HAVE_JUMP
#define TARGET_HAVE_JUMP false
#endif
#ifndef TARGET_HAVE_LOAD_MULTIPLE
#define TARGET_HAVE_LOAD_MULTIPLE false
#endif
#ifndef TARGET_HAVE_MEM_THREAD_FENCE
#define TARGET_HAVE_MEM_THREAD_FENCE false
#endif
#ifndef TARGET_HAVE_MEMORY_BARRIER
#define TARGET_HAVE_MEMORY_BARRIER false
#endif
#ifndef TARGET_HAVE_MEMORY_BLOCKAGE
#define TARGET_HAVE_MEMORY_BLOCKAGE false
#endif
#ifndef TARGET_HAVE_MOVSTR
#define TARGET_HAVE_MOVSTR false
#endif
#ifndef TARGET_HAVE_NONLOCAL_GOTO
#define TARGET_HAVE_NONLOCAL_GOTO false
#endif
#ifndef TARGET_HAVE_NONLOCAL_GOTO_RECEIVER
#define TARGET_HAVE_NONLOCAL_GOTO_RECEIVER false
#endif
#ifndef TARGET_HAVE_OACC_DIM_POS
#define TARGET_HAVE_OACC_DIM_POS false
#endif
#ifndef TARGET_HAVE_OACC_DIM_SIZE
#define TARGET_HAVE_OACC_DIM_SIZE false
#endif
#ifndef TARGET_HAVE_OACC_FORK
#define TARGET_HAVE_OACC_FORK false
#endif
#ifndef TARGET_HAVE_OACC_JOIN
#define TARGET_HAVE_OACC_JOIN false
#endif
#ifndef TARGET_HAVE_OMP_SIMT_ENTER
#define TARGET_HAVE_OMP_SIMT_ENTER false
#endif
#ifndef TARGET_HAVE_OMP_SIMT_EXIT
#define TARGET_HAVE_OMP_SIMT_EXIT false
#endif
#ifndef TARGET_HAVE_OMP_SIMT_LANE
#define TARGET_HAVE_OMP_SIMT_LANE false
#endif
#ifndef TARGET_HAVE_OMP_SIMT_LAST_LANE
#define TARGET_HAVE_OMP_SIMT_LAST_LANE false
#endif
#ifndef TARGET_HAVE_OMP_SIMT_ORDERED
#define TARGET_HAVE_OMP_SIMT_ORDERED false
#endif
#ifndef TARGET_HAVE_OMP_SIMT_VOTE_ANY
#define TARGET_HAVE_OMP_SIMT_VOTE_ANY false
#endif
#ifndef TARGET_HAVE_OMP_SIMT_XCHG_BFLY
#define TARGET_HAVE_OMP_SIMT_XCHG_BFLY false
#endif
#ifndef TARGET_HAVE_OMP_SIMT_XCHG_IDX
#define TARGET_HAVE_OMP_SIMT_XCHG_IDX false
#endif
#ifndef TARGET_HAVE_PREFETCH
#define TARGET_HAVE_PREFETCH false
#endif
#ifndef TARGET_HAVE_PROBE_STACK
#define TARGET_HAVE_PROBE_STACK false
#endif
#ifndef TARGET_HAVE_PROBE_STACK_ADDRESS
#define TARGET_HAVE_PROBE_STACK_ADDRESS false
#endif
#ifndef TARGET_HAVE_PROLOGUE
#define TARGET_HAVE_PROLOGUE false
#endif
#ifndef TARGET_HAVE_PTR_EXTEND
#define TARGET_HAVE_PTR_EXTEND false
#endif
#ifndef TARGET_HAVE_RELOAD_LOAD_ADDRESS
#define TARGET_HAVE_RELOAD_LOAD_ADDRESS false
#endif
#ifndef TARGET_HAVE_RESTORE_STACK_BLOCK
#define TARGET_HAVE_RESTORE_STACK_BLOCK false
#endif
#ifndef TARGET_HAVE_RESTORE_STACK_FUNCTION
#define TARGET_HAVE_RESTORE_STACK_FUNCTION false
#endif
#ifndef TARGET_HAVE_RESTORE_STACK_NONLOCAL
#define TARGET_HAVE_RESTORE_STACK_NONLOCAL false
#endif
#ifndef TARGET_HAVE_RETURN
#define TARGET_HAVE_RETURN false
#endif
#ifndef TARGET_HAVE_SAVE_STACK_BLOCK
#define TARGET_HAVE_SAVE_STACK_BLOCK false
#endif
#ifndef TARGET_HAVE_SAVE_STACK_FUNCTION
#define TARGET_HAVE_SAVE_STACK_FUNCTION false
#endif
#ifndef TARGET_HAVE_SAVE_STACK_NONLOCAL
#define TARGET_HAVE_SAVE_STACK_NONLOCAL false
#endif
#ifndef TARGET_HAVE_SIBCALL
#define TARGET_HAVE_SIBCALL false
#endif
#ifndef TARGET_HAVE_SIBCALL_EPILOGUE
#define TARGET_HAVE_SIBCALL_EPILOGUE false
#endif
#ifndef TARGET_HAVE_SIBCALL_VALUE
#define TARGET_HAVE_SIBCALL_VALUE false
#endif
#ifndef TARGET_HAVE_SIMPLE_RETURN
#define TARGET_HAVE_SIMPLE_RETURN false
#endif
#ifndef TARGET_HAVE_SPLIT_STACK_PROLOGUE
#define TARGET_HAVE_SPLIT_STACK_PROLOGUE false
#endif
#ifndef TARGET_HAVE_SPLIT_STACK_SPACE_CHECK
#define TARGET_HAVE_SPLIT_STACK_SPACE_CHECK false
#endif
#ifndef TARGET_HAVE_STACK_PROTECT_COMBINED_SET
#define TARGET_HAVE_STACK_PROTECT_COMBINED_SET false
#endif
#ifndef TARGET_HAVE_STACK_PROTECT_SET
#define TARGET_HAVE_STACK_PROTECT_SET false
#endif
#ifndef TARGET_HAVE_STACK_PROTECT_COMBINED_TEST
#define TARGET_HAVE_STACK_PROTECT_COMBINED_TEST false
#endif
#ifndef TARGET_HAVE_STACK_PROTECT_TEST
#define TARGET_HAVE_STACK_PROTECT_TEST false
#endif
#ifndef TARGET_HAVE_STORE_MULTIPLE
#define TARGET_HAVE_STORE_MULTIPLE false
#endif
#ifndef TARGET_HAVE_TABLEJUMP
#define TARGET_HAVE_TABLEJUMP false
#endif
#ifndef TARGET_HAVE_TRAP
#define TARGET_HAVE_TRAP false
#endif
#ifndef TARGET_HAVE_UNIQUE
#define TARGET_HAVE_UNIQUE false
#endif
#ifndef TARGET_HAVE_UNTYPED_CALL
#define TARGET_HAVE_UNTYPED_CALL false
#endif
#ifndef TARGET_HAVE_UNTYPED_RETURN
#define TARGET_HAVE_UNTYPED_RETURN false
#endif
#ifndef TARGET_GEN_ALLOCATE_STACK
#define TARGET_GEN_ALLOCATE_STACK NULL
#endif
#ifndef TARGET_GEN_ATOMIC_TEST_AND_SET
#define TARGET_GEN_ATOMIC_TEST_AND_SET NULL
#endif
#ifndef TARGET_GEN_BUILTIN_LONGJMP
#define TARGET_GEN_BUILTIN_LONGJMP NULL
#endif
#ifndef TARGET_GEN_BUILTIN_SETJMP_RECEIVER
#define TARGET_GEN_BUILTIN_SETJMP_RECEIVER NULL
#endif
#ifndef TARGET_GEN_BUILTIN_SETJMP_SETUP
#define TARGET_GEN_BUILTIN_SETJMP_SETUP NULL
#endif
#ifndef TARGET_GEN_CANONICALIZE_FUNCPTR_FOR_COMPARE
#define TARGET_GEN_CANONICALIZE_FUNCPTR_FOR_COMPARE NULL
#endif
#ifndef TARGET_GEN_CALL
#define TARGET_GEN_CALL NULL
#endif
#ifndef TARGET_GEN_CALL_POP
#define TARGET_GEN_CALL_POP NULL
#endif
#ifndef TARGET_GEN_CALL_VALUE
#define TARGET_GEN_CALL_VALUE NULL
#endif
#ifndef TARGET_GEN_CALL_VALUE_POP
#define TARGET_GEN_CALL_VALUE_POP NULL
#endif
#ifndef TARGET_GEN_CASESI
#define TARGET_GEN_CASESI NULL
#endif
#ifndef TARGET_GEN_CHECK_STACK
#define TARGET_GEN_CHECK_STACK NULL
#endif
#ifndef TARGET_GEN_CLEAR_CACHE
#define TARGET_GEN_CLEAR_CACHE NULL
#endif
#ifndef TARGET_GEN_DOLOOP_BEGIN
#define TARGET_GEN_DOLOOP_BEGIN NULL
#endif
#ifndef TARGET_GEN_DOLOOP_END
#define TARGET_GEN_DOLOOP_END NULL
#endif
#ifndef TARGET_GEN_EH_RETURN
#define TARGET_GEN_EH_RETURN NULL
#endif
#ifndef TARGET_GEN_EPILOGUE
#define TARGET_GEN_EPILOGUE NULL
#endif
#ifndef TARGET_GEN_EXCEPTION_RECEIVER
#define TARGET_GEN_EXCEPTION_RECEIVER NULL
#endif
#ifndef TARGET_GEN_EXTV
#define TARGET_GEN_EXTV NULL
#endif
#ifndef TARGET_GEN_EXTZV
#define TARGET_GEN_EXTZV NULL
#endif
#ifndef TARGET_GEN_INDIRECT_JUMP
#define TARGET_GEN_INDIRECT_JUMP NULL
#endif
#ifndef TARGET_GEN_INSV
#define TARGET_GEN_INSV NULL
#endif
#ifndef TARGET_GEN_JUMP
#define TARGET_GEN_JUMP NULL
#endif
#ifndef TARGET_GEN_LOAD_MULTIPLE
#define TARGET_GEN_LOAD_MULTIPLE NULL
#endif
#ifndef TARGET_GEN_MEM_THREAD_FENCE
#define TARGET_GEN_MEM_THREAD_FENCE NULL
#endif
#ifndef TARGET_GEN_MEMORY_BARRIER
#define TARGET_GEN_MEMORY_BARRIER NULL
#endif
#ifndef TARGET_GEN_MEMORY_BLOCKAGE
#define TARGET_GEN_MEMORY_BLOCKAGE NULL
#endif
#ifndef TARGET_GEN_MOVSTR
#define TARGET_GEN_MOVSTR NULL
#endif
#ifndef TARGET_GEN_NONLOCAL_GOTO
#define TARGET_GEN_NONLOCAL_GOTO NULL
#endif
#ifndef TARGET_GEN_NONLOCAL_GOTO_RECEIVER
#define TARGET_GEN_NONLOCAL_GOTO_RECEIVER NULL
#endif
#ifndef TARGET_GEN_OACC_DIM_POS
#define TARGET_GEN_OACC_DIM_POS NULL
#endif
#ifndef TARGET_GEN_OACC_DIM_SIZE
#define TARGET_GEN_OACC_DIM_SIZE NULL
#endif
#ifndef TARGET_GEN_OACC_FORK
#define TARGET_GEN_OACC_FORK NULL
#endif
#ifndef TARGET_GEN_OACC_JOIN
#define TARGET_GEN_OACC_JOIN NULL
#endif
#ifndef TARGET_GEN_OMP_SIMT_ENTER
#define TARGET_GEN_OMP_SIMT_ENTER NULL
#endif
#ifndef TARGET_GEN_OMP_SIMT_EXIT
#define TARGET_GEN_OMP_SIMT_EXIT NULL
#endif
#ifndef TARGET_GEN_OMP_SIMT_LANE
#define TARGET_GEN_OMP_SIMT_LANE NULL
#endif
#ifndef TARGET_GEN_OMP_SIMT_LAST_LANE
#define TARGET_GEN_OMP_SIMT_LAST_LANE NULL
#endif
#ifndef TARGET_GEN_OMP_SIMT_ORDERED
#define TARGET_GEN_OMP_SIMT_ORDERED NULL
#endif
#ifndef TARGET_GEN_OMP_SIMT_VOTE_ANY
#define TARGET_GEN_OMP_SIMT_VOTE_ANY NULL
#endif
#ifndef TARGET_GEN_OMP_SIMT_XCHG_BFLY
#define TARGET_GEN_OMP_SIMT_XCHG_BFLY NULL
#endif
#ifndef TARGET_GEN_OMP_SIMT_XCHG_IDX
#define TARGET_GEN_OMP_SIMT_XCHG_IDX NULL
#endif
#ifndef TARGET_GEN_PREFETCH
#define TARGET_GEN_PREFETCH NULL
#endif
#ifndef TARGET_GEN_PROBE_STACK
#define TARGET_GEN_PROBE_STACK NULL
#endif
#ifndef TARGET_GEN_PROBE_STACK_ADDRESS
#define TARGET_GEN_PROBE_STACK_ADDRESS NULL
#endif
#ifndef TARGET_GEN_PROLOGUE
#define TARGET_GEN_PROLOGUE NULL
#endif
#ifndef TARGET_GEN_PTR_EXTEND
#define TARGET_GEN_PTR_EXTEND NULL
#endif
#ifndef TARGET_GEN_RELOAD_LOAD_ADDRESS
#define TARGET_GEN_RELOAD_LOAD_ADDRESS NULL
#endif
#ifndef TARGET_GEN_RESTORE_STACK_BLOCK
#define TARGET_GEN_RESTORE_STACK_BLOCK NULL
#endif
#ifndef TARGET_GEN_RESTORE_STACK_FUNCTION
#define TARGET_GEN_RESTORE_STACK_FUNCTION NULL
#endif
#ifndef TARGET_GEN_RESTORE_STACK_NONLOCAL
#define TARGET_GEN_RESTORE_STACK_NONLOCAL NULL
#endif
#ifndef TARGET_GEN_RETURN
#define TARGET_GEN_RETURN NULL
#endif
#ifndef TARGET_GEN_SAVE_STACK_BLOCK
#define TARGET_GEN_SAVE_STACK_BLOCK NULL
#endif
#ifndef TARGET_GEN_SAVE_STACK_FUNCTION
#define TARGET_GEN_SAVE_STACK_FUNCTION NULL
#endif
#ifndef TARGET_GEN_SAVE_STACK_NONLOCAL
#define TARGET_GEN_SAVE_STACK_NONLOCAL NULL
#endif
#ifndef TARGET_GEN_SIBCALL
#define TARGET_GEN_SIBCALL NULL
#endif
#ifndef TARGET_GEN_SIBCALL_EPILOGUE
#define TARGET_GEN_SIBCALL_EPILOGUE NULL
#endif
#ifndef TARGET_GEN_SIBCALL_VALUE
#define TARGET_GEN_SIBCALL_VALUE NULL
#endif
#ifndef TARGET_GEN_SIMPLE_RETURN
#define TARGET_GEN_SIMPLE_RETURN NULL
#endif
#ifndef TARGET_GEN_SPLIT_STACK_PROLOGUE
#define TARGET_GEN_SPLIT_STACK_PROLOGUE NULL
#endif
#ifndef TARGET_GEN_SPLIT_STACK_SPACE_CHECK
#define TARGET_GEN_SPLIT_STACK_SPACE_CHECK NULL
#endif
#ifndef TARGET_GEN_STACK_PROTECT_COMBINED_SET
#define TARGET_GEN_STACK_PROTECT_COMBINED_SET NULL
#endif
#ifndef TARGET_GEN_STACK_PROTECT_SET
#define TARGET_GEN_STACK_PROTECT_SET NULL
#endif
#ifndef TARGET_GEN_STACK_PROTECT_COMBINED_TEST
#define TARGET_GEN_STACK_PROTECT_COMBINED_TEST NULL
#endif
#ifndef TARGET_GEN_STACK_PROTECT_TEST
#define TARGET_GEN_STACK_PROTECT_TEST NULL
#endif
#ifndef TARGET_GEN_STORE_MULTIPLE
#define TARGET_GEN_STORE_MULTIPLE NULL
#endif
#ifndef TARGET_GEN_TABLEJUMP
#define TARGET_GEN_TABLEJUMP NULL
#endif
#ifndef TARGET_GEN_TRAP
#define TARGET_GEN_TRAP NULL
#endif
#ifndef TARGET_GEN_UNIQUE
#define TARGET_GEN_UNIQUE NULL
#endif
#ifndef TARGET_GEN_UNTYPED_CALL
#define TARGET_GEN_UNTYPED_CALL NULL
#endif
#ifndef TARGET_GEN_UNTYPED_RETURN
#define TARGET_GEN_UNTYPED_RETURN NULL
#endif
#ifndef TARGET_CODE_FOR_ALLOCATE_STACK
#define TARGET_CODE_FOR_ALLOCATE_STACK CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_ATOMIC_TEST_AND_SET
#define TARGET_CODE_FOR_ATOMIC_TEST_AND_SET CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_BUILTIN_LONGJMP
#define TARGET_CODE_FOR_BUILTIN_LONGJMP CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_BUILTIN_SETJMP_RECEIVER
#define TARGET_CODE_FOR_BUILTIN_SETJMP_RECEIVER CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_BUILTIN_SETJMP_SETUP
#define TARGET_CODE_FOR_BUILTIN_SETJMP_SETUP CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_CANONICALIZE_FUNCPTR_FOR_COMPARE
#define TARGET_CODE_FOR_CANONICALIZE_FUNCPTR_FOR_COMPARE CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_CALL
#define TARGET_CODE_FOR_CALL CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_CALL_POP
#define TARGET_CODE_FOR_CALL_POP CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_CALL_VALUE
#define TARGET_CODE_FOR_CALL_VALUE CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_CALL_VALUE_POP
#define TARGET_CODE_FOR_CALL_VALUE_POP CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_CASESI
#define TARGET_CODE_FOR_CASESI CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_CHECK_STACK
#define TARGET_CODE_FOR_CHECK_STACK CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_CLEAR_CACHE
#define TARGET_CODE_FOR_CLEAR_CACHE CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_DOLOOP_BEGIN
#define TARGET_CODE_FOR_DOLOOP_BEGIN CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_DOLOOP_END
#define TARGET_CODE_FOR_DOLOOP_END CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_EH_RETURN
#define TARGET_CODE_FOR_EH_RETURN CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_EPILOGUE
#define TARGET_CODE_FOR_EPILOGUE CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_EXCEPTION_RECEIVER
#define TARGET_CODE_FOR_EXCEPTION_RECEIVER CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_EXTV
#define TARGET_CODE_FOR_EXTV CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_EXTZV
#define TARGET_CODE_FOR_EXTZV CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_INDIRECT_JUMP
#define TARGET_CODE_FOR_INDIRECT_JUMP CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_INSV
#define TARGET_CODE_FOR_INSV CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_JUMP
#define TARGET_CODE_FOR_JUMP CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_LOAD_MULTIPLE
#define TARGET_CODE_FOR_LOAD_MULTIPLE CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_MEM_THREAD_FENCE
#define TARGET_CODE_FOR_MEM_THREAD_FENCE CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_MEMORY_BARRIER
#define TARGET_CODE_FOR_MEMORY_BARRIER CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_MEMORY_BLOCKAGE
#define TARGET_CODE_FOR_MEMORY_BLOCKAGE CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_MOVSTR
#define TARGET_CODE_FOR_MOVSTR CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_NONLOCAL_GOTO
#define TARGET_CODE_FOR_NONLOCAL_GOTO CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_NONLOCAL_GOTO_RECEIVER
#define TARGET_CODE_FOR_NONLOCAL_GOTO_RECEIVER CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_OACC_DIM_POS
#define TARGET_CODE_FOR_OACC_DIM_POS CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_OACC_DIM_SIZE
#define TARGET_CODE_FOR_OACC_DIM_SIZE CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_OACC_FORK
#define TARGET_CODE_FOR_OACC_FORK CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_OACC_JOIN
#define TARGET_CODE_FOR_OACC_JOIN CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_OMP_SIMT_ENTER
#define TARGET_CODE_FOR_OMP_SIMT_ENTER CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_OMP_SIMT_EXIT
#define TARGET_CODE_FOR_OMP_SIMT_EXIT CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_OMP_SIMT_LANE
#define TARGET_CODE_FOR_OMP_SIMT_LANE CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_OMP_SIMT_LAST_LANE
#define TARGET_CODE_FOR_OMP_SIMT_LAST_LANE CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_OMP_SIMT_ORDERED
#define TARGET_CODE_FOR_OMP_SIMT_ORDERED CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_OMP_SIMT_VOTE_ANY
#define TARGET_CODE_FOR_OMP_SIMT_VOTE_ANY CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_OMP_SIMT_XCHG_BFLY
#define TARGET_CODE_FOR_OMP_SIMT_XCHG_BFLY CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_OMP_SIMT_XCHG_IDX
#define TARGET_CODE_FOR_OMP_SIMT_XCHG_IDX CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_PREFETCH
#define TARGET_CODE_FOR_PREFETCH CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_PROBE_STACK
#define TARGET_CODE_FOR_PROBE_STACK CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_PROBE_STACK_ADDRESS
#define TARGET_CODE_FOR_PROBE_STACK_ADDRESS CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_PROLOGUE
#define TARGET_CODE_FOR_PROLOGUE CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_PTR_EXTEND
#define TARGET_CODE_FOR_PTR_EXTEND CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_RELOAD_LOAD_ADDRESS
#define TARGET_CODE_FOR_RELOAD_LOAD_ADDRESS CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_RESTORE_STACK_BLOCK
#define TARGET_CODE_FOR_RESTORE_STACK_BLOCK CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_RESTORE_STACK_FUNCTION
#define TARGET_CODE_FOR_RESTORE_STACK_FUNCTION CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_RESTORE_STACK_NONLOCAL
#define TARGET_CODE_FOR_RESTORE_STACK_NONLOCAL CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_RETURN
#define TARGET_CODE_FOR_RETURN CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_SAVE_STACK_BLOCK
#define TARGET_CODE_FOR_SAVE_STACK_BLOCK CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_SAVE_STACK_FUNCTION
#define TARGET_CODE_FOR_SAVE_STACK_FUNCTION CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_SAVE_STACK_NONLOCAL
#define TARGET_CODE_FOR_SAVE_STACK_NONLOCAL CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_SIBCALL
#define TARGET_CODE_FOR_SIBCALL CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_SIBCALL_EPILOGUE
#define TARGET_CODE_FOR_SIBCALL_EPILOGUE CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_SIBCALL_VALUE
#define TARGET_CODE_FOR_SIBCALL_VALUE CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_SIMPLE_RETURN
#define TARGET_CODE_FOR_SIMPLE_RETURN CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_SPLIT_STACK_PROLOGUE
#define TARGET_CODE_FOR_SPLIT_STACK_PROLOGUE CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_SPLIT_STACK_SPACE_CHECK
#define TARGET_CODE_FOR_SPLIT_STACK_SPACE_CHECK CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_STACK_PROTECT_COMBINED_SET
#define TARGET_CODE_FOR_STACK_PROTECT_COMBINED_SET CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_STACK_PROTECT_SET
#define TARGET_CODE_FOR_STACK_PROTECT_SET CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_STACK_PROTECT_COMBINED_TEST
#define TARGET_CODE_FOR_STACK_PROTECT_COMBINED_TEST CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_STACK_PROTECT_TEST
#define TARGET_CODE_FOR_STACK_PROTECT_TEST CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_STORE_MULTIPLE
#define TARGET_CODE_FOR_STORE_MULTIPLE CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_TABLEJUMP
#define TARGET_CODE_FOR_TABLEJUMP CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_TRAP
#define TARGET_CODE_FOR_TRAP CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_UNIQUE
#define TARGET_CODE_FOR_UNIQUE CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_UNTYPED_CALL
#define TARGET_CODE_FOR_UNTYPED_CALL CODE_FOR_nothing
#endif
#ifndef TARGET_CODE_FOR_UNTYPED_RETURN
#define TARGET_CODE_FOR_UNTYPED_RETURN CODE_FOR_nothing
#endif
#ifndef TARGET_RUN_TARGET_SELFTESTS
#define TARGET_RUN_TARGET_SELFTESTS NULL
#endif

#define TARGET_INITIALIZER                                                     \
    {                                                                          \
        TARGET_ASM_OUT, TARGET_SCHED, TARGET_SIMD_CLONE, TARGET_SIMT,          \
            TARGET_GOACC, TARGET_VECTORIZE, TARGET_PREFERRED_ELSE_VALUE,       \
            TARGET_RECORD_OFFLOAD_SYMBOL, TARGET_ABSOLUTE_BIGGEST_ALIGNMENT,   \
            TARGET_OVERRIDE_OPTIONS_AFTER_CHANGE, TARGET_OFFLOAD_OPTIONS,      \
            TARGET_EH_RETURN_FILTER_MODE, TARGET_LIBGCC_CMP_RETURN_MODE,       \
            TARGET_LIBGCC_SHIFT_COUNT_MODE, TARGET_UNWIND_WORD_MODE,           \
            TARGET_MERGE_DECL_ATTRIBUTES, TARGET_MERGE_TYPE_ATTRIBUTES,        \
            TARGET_ATTRIBUTE_TABLE, TARGET_ATTRIBUTE_TAKES_IDENTIFIER_P,       \
            TARGET_COMP_TYPE_ATTRIBUTES, TARGET_SET_DEFAULT_TYPE_ATTRIBUTES,   \
            TARGET_INSERT_ATTRIBUTES, TARGET_FUNCTION_ATTRIBUTE_INLINABLE_P,   \
            TARGET_MS_BITFIELD_LAYOUT_P, TARGET_WORDS_BIG_ENDIAN,              \
            TARGET_FLOAT_WORDS_BIG_ENDIAN,                                     \
            TARGET_FLOAT_EXCEPTIONS_ROUNDING_SUPPORTED_P,                      \
            TARGET_DECIMAL_FLOAT_SUPPORTED_P, TARGET_FIXED_POINT_SUPPORTED_P,  \
            TARGET_ALIGN_ANON_BITFIELD, TARGET_NARROW_VOLATILE_BITFIELD,       \
            TARGET_INIT_BUILTINS, TARGET_BUILTIN_DECL, TARGET_EXPAND_BUILTIN,  \
            TARGET_RESOLVE_OVERLOADED_BUILTIN, TARGET_FOLD_BUILTIN,            \
            TARGET_GIMPLE_FOLD_BUILTIN, TARGET_COMPARE_VERSION_PRIORITY,       \
            TARGET_GENERATE_VERSION_DISPATCHER_BODY,                           \
            TARGET_GET_FUNCTION_VERSIONS_DISPATCHER,                           \
            TARGET_BUILTIN_RECIPROCAL, TARGET_MANGLE_TYPE,                     \
            TARGET_INIT_LIBFUNCS, TARGET_LIBFUNC_GNU_PREFIX,                   \
            TARGET_SECTION_TYPE_FLAGS, TARGET_LIBC_HAS_FUNCTION,               \
            TARGET_CANNOT_MODIFY_JUMPS_P, TARGET_CAN_FOLLOW_JUMP,              \
            TARGET_BRANCH_TARGET_REGISTER_CLASS,                               \
            TARGET_BRANCH_TARGET_REGISTER_CALLEE_SAVED,                        \
            TARGET_HAVE_CONDITIONAL_EXECUTION, TARGET_GEN_CCMP_FIRST,          \
            TARGET_GEN_CCMP_NEXT, TARGET_LOOP_UNROLL_ADJUST,                   \
            TARGET_LEGITIMATE_CONSTANT_P, TARGET_CANNOT_FORCE_CONST_MEM,       \
            TARGET_CANNOT_COPY_INSN_P, TARGET_COMMUTATIVE_P,                   \
            TARGET_MODE_DEPENDENT_ADDRESS_P, TARGET_LEGITIMIZE_ADDRESS,        \
            TARGET_DELEGITIMIZE_ADDRESS, TARGET_CONST_NOT_OK_FOR_DEBUG_P,      \
            TARGET_LEGITIMATE_ADDRESS_P, TARGET_USE_BLOCKS_FOR_CONSTANT_P,     \
            TARGET_USE_BLOCKS_FOR_DECL_P, TARGET_MIN_ANCHOR_OFFSET,            \
            TARGET_MAX_ANCHOR_OFFSET, TARGET_USE_ANCHORS_FOR_SYMBOL_P,         \
            TARGET_HAS_IFUNC_P, TARGET_FUNCTION_OK_FOR_SIBCALL,                \
            TARGET_SET_CURRENT_FUNCTION, TARGET_IN_SMALL_DATA_P,               \
            TARGET_BINDS_LOCAL_P, TARGET_PROFILE_BEFORE_PROLOGUE,              \
            TARGET_KEEP_LEAF_WHEN_PROFILED, TARGET_MANGLE_DECL_ASSEMBLER_NAME, \
            TARGET_ENCODE_SECTION_INFO, TARGET_STRIP_NAME_ENCODING,            \
            TARGET_SHIFT_TRUNCATION_MASK, TARGET_MIN_DIVISIONS_FOR_RECIP_MUL,  \
            TARGET_TRULY_NOOP_TRUNCATION, TARGET_MODE_REP_EXTENDED,            \
            TARGET_SETJMP_PRESERVES_NONVOLATILE_REGS_P,                        \
            TARGET_VALID_POINTER_MODE, TARGET_REF_MAY_ALIAS_ERRNO,             \
            TARGET_ADDR_SPACE_HOOKS, TARGET_STATIC_RTX_ALIGNMENT,              \
            TARGET_CONSTANT_ALIGNMENT, TARGET_TRANSLATE_MODE_ATTRIBUTE,        \
            TARGET_SCALAR_MODE_SUPPORTED_P, TARGET_VECTOR_MODE_SUPPORTED_P,    \
            TARGET_VECTOR_ALIGNMENT, TARGET_ARRAY_MODE,                        \
            TARGET_ARRAY_MODE_SUPPORTED_P,                                     \
            TARGET_LIBGCC_FLOATING_MODE_SUPPORTED_P, TARGET_FLOATN_MODE,       \
            TARGET_FLOATN_BUILTIN_P, TARGET_REGISTER_MOVE_COST,                \
            TARGET_MEMORY_MOVE_COST, TARGET_USE_BY_PIECES_INFRASTRUCTURE_P,    \
            TARGET_COMPARE_BY_PIECES_BRANCH_RATIO,                             \
            TARGET_SLOW_UNALIGNED_ACCESS, TARGET_OPTAB_SUPPORTED_P,            \
            TARGET_SMALL_REGISTER_CLASSES_FOR_MODE_P, TARGET_FLAGS_REGNUM,     \
            TARGET_RTX_COSTS, TARGET_ADDRESS_COST, TARGET_INSN_COST,           \
            TARGET_MAX_NOCE_IFCVT_SEQ_COST,                                    \
            TARGET_NOCE_CONVERSION_PROFITABLE_P, TARGET_ESTIMATED_POLY_VALUE,  \
            TARGET_NO_SPECULATION_IN_DELAY_SLOTS_P,                            \
            TARGET_ALLOCATE_INITIAL_VALUE, TARGET_UNSPEC_MAY_TRAP_P,           \
            TARGET_DWARF_REGISTER_SPAN, TARGET_DWARF_FRAME_REG_MODE,           \
            TARGET_INIT_DWARF_REG_SIZES_EXTRA,                                 \
            TARGET_FIXED_CONDITION_CODE_REGS, TARGET_CC_MODES_COMPATIBLE,      \
            TARGET_MACHINE_DEPENDENT_REORG, TARGET_BUILD_BUILTIN_VA_LIST,      \
            TARGET_ENUM_VA_LIST_P, TARGET_FN_ABI_VA_LIST,                      \
            TARGET_CANONICAL_VA_LIST_TYPE, TARGET_EXPAND_BUILTIN_VA_START,     \
            TARGET_GIMPLIFY_VA_ARG_EXPR, TARGET_GET_PCH_VALIDITY,              \
            TARGET_PCH_VALID_P, TARGET_PREPARE_PCH_SAVE,                       \
            TARGET_CHECK_PCH_TARGET_FLAGS, TARGET_DEFAULT_SHORT_ENUMS,         \
            TARGET_BUILTIN_SETJMP_FRAME_VALUE, TARGET_MD_ASM_ADJUST,           \
            TARGET_DWARF_CALLING_CONVENTION, TARGET_DWARF_HANDLE_FRAME_UNSPEC, \
            TARGET_DWARF_POLY_INDETERMINATE_VALUE,                             \
            TARGET_STDARG_OPTIMIZE_HOOK, TARGET_STACK_PROTECT_GUARD,           \
            TARGET_STACK_PROTECT_FAIL, TARGET_STACK_PROTECT_RUNTIME_ENABLED_P, \
            TARGET_HAVE_SPECULATION_SAFE_VALUE, TARGET_SPECULATION_SAFE_VALUE, \
            TARGET_CAN_USE_DOLOOP_P, TARGET_INVALID_WITHIN_DOLOOP,             \
            TARGET_LEGITIMATE_COMBINED_INSN,                                   \
            TARGET_VALID_DLLIMPORT_ATTRIBUTE_P, TARGET_CONST_ANCHOR,           \
            TARGET_MEMMODEL_CHECK, TARGET_ASAN_SHADOW_OFFSET, TARGET_CALLS,    \
            TARGET_USE_PSEUDO_PIC_REG, TARGET_INIT_PIC_REG,                    \
            TARGET_INVALID_CONVERSION, TARGET_INVALID_UNARY_OP,                \
            TARGET_INVALID_BINARY_OP, TARGET_PROMOTED_TYPE,                    \
            TARGET_CONVERT_TO_TYPE, TARGET_CAN_CHANGE_MODE_CLASS,              \
            TARGET_IRA_CHANGE_PSEUDO_ALLOCNO_CLASS, TARGET_LRA_P,              \
            TARGET_REGISTER_PRIORITY, TARGET_REGISTER_USAGE_LEVELING_P,        \
            TARGET_DIFFERENT_ADDR_DISPLACEMENT_P, TARGET_SPILL_CLASS,          \
            TARGET_ADDITIONAL_ALLOCNO_CLASS_P, TARGET_CSTORE_MODE,             \
            TARGET_COMPUTE_PRESSURE_CLASSES, TARGET_MEMBER_TYPE_FORCES_BLK,    \
            TARGET_EXPAND_DIVMOD_LIBFUNC, TARGET_SECONDARY_RELOAD,             \
            TARGET_SECONDARY_MEMORY_NEEDED,                                    \
            TARGET_SECONDARY_MEMORY_NEEDED_MODE,                               \
            TARGET_PREFERRED_RELOAD_CLASS,                                     \
            TARGET_PREFERRED_OUTPUT_RELOAD_CLASS,                              \
            TARGET_SELECT_EARLY_REMAT_MODES, TARGET_CLASS_LIKELY_SPILLED_P,    \
            TARGET_CLASS_MAX_NREGS, TARGET_PREFERRED_RENAME_CLASS,             \
            TARGET_CANNOT_SUBSTITUTE_MEM_EQUIV_P,                              \
            TARGET_LEGITIMIZE_ADDRESS_DISPLACEMENT, TARGET_EXPAND_TO_RTL_HOOK, \
            TARGET_INSTANTIATE_DECLS, TARGET_HARD_REGNO_NREGS,                 \
            TARGET_HARD_REGNO_MODE_OK, TARGET_MODES_TIEABLE_P,                 \
            TARGET_HARD_REGNO_SCRATCH_OK,                                      \
            TARGET_HARD_REGNO_CALL_PART_CLOBBERED,                             \
            TARGET_RETURN_CALL_WITH_MAX_CLOBBERS,                              \
            TARGET_GET_MULTILIB_ABI_NAME,                                      \
            TARGET_REMOVE_EXTRA_CALL_PRESERVED_REGS,                           \
            TARGET_CASE_VALUES_THRESHOLD, TARGET_STARTING_FRAME_OFFSET,        \
            TARGET_COMPUTE_FRAME_LAYOUT, TARGET_FRAME_POINTER_REQUIRED,        \
            TARGET_CAN_ELIMINATE, TARGET_CONDITIONAL_REGISTER_USAGE,           \
            TARGET_STACK_CLASH_PROTECTION_ALLOCA_PROBE_RANGE, TARGET_C,        \
            TARGET_CXX, TARGET_EMUTLS, TARGET_OPTION_HOOKS,                    \
            TARGET_EXTRA_LIVE_ON_ENTRY,                                        \
            TARGET_CALL_FUSAGE_CONTAINS_NON_CALLEE_CLOBBERS,                   \
            TARGET_SET_UP_BY_PROLOGUE, TARGET_WARN_FUNC_RETURN,                \
            TARGET_SHRINK_WRAP_HOOKS, TARGET_DEBUG_UNWIND_INFO,                \
            TARGET_RESET_LOCATION_VIEW, TARGET_CANONICALIZE_COMPARISON,        \
            TARGET_MIN_ARITHMETIC_PRECISION,                                   \
            TARGET_ATOMIC_TEST_AND_SET_TRUEVAL, TARGET_ATOMIC_ALIGN_FOR_MODE,  \
            TARGET_ATOMIC_ASSIGN_EXPAND_FENV,                                  \
            TARGET_HAVE_SWITCHABLE_BSS_SECTIONS, TARGET_HAVE_CTORS_DTORS,      \
            TARGET_HAVE_TLS, TARGET_HAVE_SRODATA_SECTION,                      \
            TARGET_TERMINATE_DW2_EH_FRAME_INFO, TARGET_ASM_FILE_START_APP_OFF, \
            TARGET_ASM_FILE_START_FILE_DIRECTIVE, TARGET_ARM_EABI_UNWINDER,    \
            TARGET_WANT_DEBUG_PUB_SECTIONS, TARGET_DELAY_SCHED2,               \
            TARGET_DELAY_VARTRACK, TARGET_NO_REGISTER_ALLOCATION,              \
            TARGET_TOGGLE_, TARGET_HAVE_ALLOCATE_STACK,                        \
            TARGET_HAVE_ATOMIC_TEST_AND_SET, TARGET_HAVE_BUILTIN_LONGJMP,      \
            TARGET_HAVE_BUILTIN_SETJMP_RECEIVER,                               \
            TARGET_HAVE_BUILTIN_SETJMP_SETUP,                                  \
            TARGET_HAVE_CANONICALIZE_FUNCPTR_FOR_COMPARE, TARGET_HAVE_CALL,    \
            TARGET_HAVE_CALL_POP, TARGET_HAVE_CALL_VALUE,                      \
            TARGET_HAVE_CALL_VALUE_POP, TARGET_HAVE_CASESI,                    \
            TARGET_HAVE_CHECK_STACK, TARGET_HAVE_CLEAR_CACHE,                  \
            TARGET_HAVE_DOLOOP_BEGIN, TARGET_HAVE_DOLOOP_END,                  \
            TARGET_HAVE_EH_RETURN, TARGET_HAVE_EPILOGUE,                       \
            TARGET_HAVE_EXCEPTION_RECEIVER, TARGET_HAVE_EXTV,                  \
            TARGET_HAVE_EXTZV, TARGET_HAVE_INDIRECT_JUMP, TARGET_HAVE_INSV,    \
            TARGET_HAVE_JUMP, TARGET_HAVE_LOAD_MULTIPLE,                       \
            TARGET_HAVE_MEM_THREAD_FENCE, TARGET_HAVE_MEMORY_BARRIER,          \
            TARGET_HAVE_MEMORY_BLOCKAGE, TARGET_HAVE_MOVSTR,                   \
            TARGET_HAVE_NONLOCAL_GOTO, TARGET_HAVE_NONLOCAL_GOTO_RECEIVER,     \
            TARGET_HAVE_OACC_DIM_POS, TARGET_HAVE_OACC_DIM_SIZE,               \
            TARGET_HAVE_OACC_FORK, TARGET_HAVE_OACC_JOIN,                      \
            TARGET_HAVE_OMP_SIMT_ENTER, TARGET_HAVE_OMP_SIMT_EXIT,             \
            TARGET_HAVE_OMP_SIMT_LANE, TARGET_HAVE_OMP_SIMT_LAST_LANE,         \
            TARGET_HAVE_OMP_SIMT_ORDERED, TARGET_HAVE_OMP_SIMT_VOTE_ANY,       \
            TARGET_HAVE_OMP_SIMT_XCHG_BFLY, TARGET_HAVE_OMP_SIMT_XCHG_IDX,     \
            TARGET_HAVE_PREFETCH, TARGET_HAVE_PROBE_STACK,                     \
            TARGET_HAVE_PROBE_STACK_ADDRESS, TARGET_HAVE_PROLOGUE,             \
            TARGET_HAVE_PTR_EXTEND, TARGET_HAVE_RELOAD_LOAD_ADDRESS,           \
            TARGET_HAVE_RESTORE_STACK_BLOCK,                                   \
            TARGET_HAVE_RESTORE_STACK_FUNCTION,                                \
            TARGET_HAVE_RESTORE_STACK_NONLOCAL, TARGET_HAVE_RETURN,            \
            TARGET_HAVE_SAVE_STACK_BLOCK, TARGET_HAVE_SAVE_STACK_FUNCTION,     \
            TARGET_HAVE_SAVE_STACK_NONLOCAL, TARGET_HAVE_SIBCALL,              \
            TARGET_HAVE_SIBCALL_EPILOGUE, TARGET_HAVE_SIBCALL_VALUE,           \
            TARGET_HAVE_SIMPLE_RETURN, TARGET_HAVE_SPLIT_STACK_PROLOGUE,       \
            TARGET_HAVE_SPLIT_STACK_SPACE_CHECK,                               \
            TARGET_HAVE_STACK_PROTECT_COMBINED_SET,                            \
            TARGET_HAVE_STACK_PROTECT_SET,                                     \
            TARGET_HAVE_STACK_PROTECT_COMBINED_TEST,                           \
            TARGET_HAVE_STACK_PROTECT_TEST, TARGET_HAVE_STORE_MULTIPLE,        \
            TARGET_HAVE_TABLEJUMP, TARGET_HAVE_TRAP, TARGET_HAVE_UNIQUE,       \
            TARGET_HAVE_UNTYPED_CALL, TARGET_HAVE_UNTYPED_RETURN,              \
            TARGET_GEN_ALLOCATE_STACK, TARGET_GEN_ATOMIC_TEST_AND_SET,         \
            TARGET_GEN_BUILTIN_LONGJMP, TARGET_GEN_BUILTIN_SETJMP_RECEIVER,    \
            TARGET_GEN_BUILTIN_SETJMP_SETUP,                                   \
            TARGET_GEN_CANONICALIZE_FUNCPTR_FOR_COMPARE, TARGET_GEN_CALL,      \
            TARGET_GEN_CALL_POP, TARGET_GEN_CALL_VALUE,                        \
            TARGET_GEN_CALL_VALUE_POP, TARGET_GEN_CASESI,                      \
            TARGET_GEN_CHECK_STACK, TARGET_GEN_CLEAR_CACHE,                    \
            TARGET_GEN_DOLOOP_BEGIN, TARGET_GEN_DOLOOP_END,                    \
            TARGET_GEN_EH_RETURN, TARGET_GEN_EPILOGUE,                         \
            TARGET_GEN_EXCEPTION_RECEIVER, TARGET_GEN_EXTV, TARGET_GEN_EXTZV,  \
            TARGET_GEN_INDIRECT_JUMP, TARGET_GEN_INSV, TARGET_GEN_JUMP,        \
            TARGET_GEN_LOAD_MULTIPLE, TARGET_GEN_MEM_THREAD_FENCE,             \
            TARGET_GEN_MEMORY_BARRIER, TARGET_GEN_MEMORY_BLOCKAGE,             \
            TARGET_GEN_MOVSTR, TARGET_GEN_NONLOCAL_GOTO,                       \
            TARGET_GEN_NONLOCAL_GOTO_RECEIVER, TARGET_GEN_OACC_DIM_POS,        \
            TARGET_GEN_OACC_DIM_SIZE, TARGET_GEN_OACC_FORK,                    \
            TARGET_GEN_OACC_JOIN, TARGET_GEN_OMP_SIMT_ENTER,                   \
            TARGET_GEN_OMP_SIMT_EXIT, TARGET_GEN_OMP_SIMT_LANE,                \
            TARGET_GEN_OMP_SIMT_LAST_LANE, TARGET_GEN_OMP_SIMT_ORDERED,        \
            TARGET_GEN_OMP_SIMT_VOTE_ANY, TARGET_GEN_OMP_SIMT_XCHG_BFLY,       \
            TARGET_GEN_OMP_SIMT_XCHG_IDX, TARGET_GEN_PREFETCH,                 \
            TARGET_GEN_PROBE_STACK, TARGET_GEN_PROBE_STACK_ADDRESS,            \
            TARGET_GEN_PROLOGUE, TARGET_GEN_PTR_EXTEND,                        \
            TARGET_GEN_RELOAD_LOAD_ADDRESS, TARGET_GEN_RESTORE_STACK_BLOCK,    \
            TARGET_GEN_RESTORE_STACK_FUNCTION,                                 \
            TARGET_GEN_RESTORE_STACK_NONLOCAL, TARGET_GEN_RETURN,              \
            TARGET_GEN_SAVE_STACK_BLOCK, TARGET_GEN_SAVE_STACK_FUNCTION,       \
            TARGET_GEN_SAVE_STACK_NONLOCAL, TARGET_GEN_SIBCALL,                \
            TARGET_GEN_SIBCALL_EPILOGUE, TARGET_GEN_SIBCALL_VALUE,             \
            TARGET_GEN_SIMPLE_RETURN, TARGET_GEN_SPLIT_STACK_PROLOGUE,         \
            TARGET_GEN_SPLIT_STACK_SPACE_CHECK,                                \
            TARGET_GEN_STACK_PROTECT_COMBINED_SET,                             \
            TARGET_GEN_STACK_PROTECT_SET,                                      \
            TARGET_GEN_STACK_PROTECT_COMBINED_TEST,                            \
            TARGET_GEN_STACK_PROTECT_TEST, TARGET_GEN_STORE_MULTIPLE,          \
            TARGET_GEN_TABLEJUMP, TARGET_GEN_TRAP, TARGET_GEN_UNIQUE,          \
            TARGET_GEN_UNTYPED_CALL, TARGET_GEN_UNTYPED_RETURN,                \
            TARGET_CODE_FOR_ALLOCATE_STACK,                                    \
            TARGET_CODE_FOR_ATOMIC_TEST_AND_SET,                               \
            TARGET_CODE_FOR_BUILTIN_LONGJMP,                                   \
            TARGET_CODE_FOR_BUILTIN_SETJMP_RECEIVER,                           \
            TARGET_CODE_FOR_BUILTIN_SETJMP_SETUP,                              \
            TARGET_CODE_FOR_CANONICALIZE_FUNCPTR_FOR_COMPARE,                  \
            TARGET_CODE_FOR_CALL, TARGET_CODE_FOR_CALL_POP,                    \
            TARGET_CODE_FOR_CALL_VALUE, TARGET_CODE_FOR_CALL_VALUE_POP,        \
            TARGET_CODE_FOR_CASESI, TARGET_CODE_FOR_CHECK_STACK,               \
            TARGET_CODE_FOR_CLEAR_CACHE, TARGET_CODE_FOR_DOLOOP_BEGIN,         \
            TARGET_CODE_FOR_DOLOOP_END, TARGET_CODE_FOR_EH_RETURN,             \
            TARGET_CODE_FOR_EPILOGUE, TARGET_CODE_FOR_EXCEPTION_RECEIVER,      \
            TARGET_CODE_FOR_EXTV, TARGET_CODE_FOR_EXTZV,                       \
            TARGET_CODE_FOR_INDIRECT_JUMP, TARGET_CODE_FOR_INSV,               \
            TARGET_CODE_FOR_JUMP, TARGET_CODE_FOR_LOAD_MULTIPLE,               \
            TARGET_CODE_FOR_MEM_THREAD_FENCE, TARGET_CODE_FOR_MEMORY_BARRIER,  \
            TARGET_CODE_FOR_MEMORY_BLOCKAGE, TARGET_CODE_FOR_MOVSTR,           \
            TARGET_CODE_FOR_NONLOCAL_GOTO,                                     \
            TARGET_CODE_FOR_NONLOCAL_GOTO_RECEIVER,                            \
            TARGET_CODE_FOR_OACC_DIM_POS, TARGET_CODE_FOR_OACC_DIM_SIZE,       \
            TARGET_CODE_FOR_OACC_FORK, TARGET_CODE_FOR_OACC_JOIN,              \
            TARGET_CODE_FOR_OMP_SIMT_ENTER, TARGET_CODE_FOR_OMP_SIMT_EXIT,     \
            TARGET_CODE_FOR_OMP_SIMT_LANE, TARGET_CODE_FOR_OMP_SIMT_LAST_LANE, \
            TARGET_CODE_FOR_OMP_SIMT_ORDERED,                                  \
            TARGET_CODE_FOR_OMP_SIMT_VOTE_ANY,                                 \
            TARGET_CODE_FOR_OMP_SIMT_XCHG_BFLY,                                \
            TARGET_CODE_FOR_OMP_SIMT_XCHG_IDX, TARGET_CODE_FOR_PREFETCH,       \
            TARGET_CODE_FOR_PROBE_STACK, TARGET_CODE_FOR_PROBE_STACK_ADDRESS,  \
            TARGET_CODE_FOR_PROLOGUE, TARGET_CODE_FOR_PTR_EXTEND,              \
            TARGET_CODE_FOR_RELOAD_LOAD_ADDRESS,                               \
            TARGET_CODE_FOR_RESTORE_STACK_BLOCK,                               \
            TARGET_CODE_FOR_RESTORE_STACK_FUNCTION,                            \
            TARGET_CODE_FOR_RESTORE_STACK_NONLOCAL, TARGET_CODE_FOR_RETURN,    \
            TARGET_CODE_FOR_SAVE_STACK_BLOCK,                                  \
            TARGET_CODE_FOR_SAVE_STACK_FUNCTION,                               \
            TARGET_CODE_FOR_SAVE_STACK_NONLOCAL, TARGET_CODE_FOR_SIBCALL,      \
            TARGET_CODE_FOR_SIBCALL_EPILOGUE, TARGET_CODE_FOR_SIBCALL_VALUE,   \
            TARGET_CODE_FOR_SIMPLE_RETURN,                                     \
            TARGET_CODE_FOR_SPLIT_STACK_PROLOGUE,                              \
            TARGET_CODE_FOR_SPLIT_STACK_SPACE_CHECK,                           \
            TARGET_CODE_FOR_STACK_PROTECT_COMBINED_SET,                        \
            TARGET_CODE_FOR_STACK_PROTECT_SET,                                 \
            TARGET_CODE_FOR_STACK_PROTECT_COMBINED_TEST,                       \
            TARGET_CODE_FOR_STACK_PROTECT_TEST,                                \
            TARGET_CODE_FOR_STORE_MULTIPLE, TARGET_CODE_FOR_TABLEJUMP,         \
            TARGET_CODE_FOR_TRAP, TARGET_CODE_FOR_UNIQUE,                      \
            TARGET_CODE_FOR_UNTYPED_CALL, TARGET_CODE_FOR_UNTYPED_RETURN,      \
            TARGET_RUN_TARGET_SELFTESTS,                                       \
    }

#define TARGET_ASM_OUT                                                         \
    {                                                                          \
        TARGET_ASM_OPEN_PAREN, TARGET_ASM_CLOSE_PAREN, TARGET_ASM_BYTE_OP,     \
            TARGET_ASM_ALIGNED_OP, TARGET_ASM_UNALIGNED_OP,                    \
            TARGET_ASM_INTEGER, TARGET_ASM_POST_CFI_STARTPROC,                 \
            TARGET_ASM_DECL_END, TARGET_ASM_GLOBALIZE_LABEL,                   \
            TARGET_ASM_GLOBALIZE_DECL_NAME,                                    \
            TARGET_ASM_ASSEMBLE_UNDEFINED_DECL, TARGET_ASM_EMIT_UNWIND_LABEL,  \
            TARGET_ASM_EMIT_EXCEPT_TABLE_LABEL,                                \
            TARGET_ASM_EMIT_EXCEPT_PERSONALITY, TARGET_ASM_UNWIND_EMIT,        \
            TARGET_ASM_UNWIND_EMIT_BEFORE_INSN,                                \
            TARGET_ASM_GENERATE_INTERNAL_LABEL, TARGET_ASM_INTERNAL_LABEL,     \
            TARGET_ASM_DECLARE_CONSTANT_NAME, TARGET_ASM_TTYPE,                \
            TARGET_ASM_ASSEMBLE_VISIBILITY,                                    \
            TARGET_ASM_PRINT_PATCHABLE_FUNCTION_ENTRY,                         \
            TARGET_ASM_FUNCTION_PROLOGUE, TARGET_ASM_FUNCTION_END_PROLOGUE,    \
            TARGET_ASM_FUNCTION_BEGIN_EPILOGUE, TARGET_ASM_FUNCTION_EPILOGUE,  \
            TARGET_ASM_INIT_SECTIONS, TARGET_ASM_NAMED_SECTION,                \
            TARGET_ASM_ELF_FLAGS_NUMERIC, TARGET_ASM_FUNCTION_SECTION,         \
            TARGET_ASM_FUNCTION_SWITCHED_TEXT_SECTIONS,                        \
            TARGET_ASM_RELOC_RW_MASK, TARGET_ASM_GENERATE_PIC_ADDR_DIFF_VEC,   \
            TARGET_ASM_SELECT_SECTION, TARGET_ASM_SELECT_RTX_SECTION,          \
            TARGET_ASM_UNIQUE_SECTION, TARGET_ASM_FUNCTION_RODATA_SECTION,     \
            TARGET_ASM_MERGEABLE_RODATA_PREFIX,                                \
            TARGET_ASM_TM_CLONE_TABLE_SECTION, TARGET_ASM_CONSTRUCTOR,         \
            TARGET_ASM_DESTRUCTOR, TARGET_ASM_OUTPUT_MI_THUNK,                 \
            TARGET_ASM_CAN_OUTPUT_MI_THUNK, TARGET_ASM_FILE_START,             \
            TARGET_ASM_FILE_END, TARGET_ASM_LTO_START, TARGET_ASM_LTO_END,     \
            TARGET_ASM_CODE_END, TARGET_ASM_EXTERNAL_LIBCALL,                  \
            TARGET_ASM_MARK_DECL_PRESERVED, TARGET_ASM_RECORD_GCC_SWITCHES,    \
            TARGET_ASM_RECORD_GCC_SWITCHES_SECTION, TARGET_ASM_OUTPUT_ANCHOR,  \
            TARGET_ASM_OUTPUT_IDENT, TARGET_ASM_OUTPUT_DWARF_DTPREL,           \
            TARGET_ASM_FINAL_POSTSCAN_INSN, TARGET_ASM_TRAMPOLINE_TEMPLATE,    \
            TARGET_ASM_OUTPUT_SOURCE_FILENAME,                                 \
            TARGET_ASM_OUTPUT_ADDR_CONST_EXTRA, TARGET_PRINT_OPERAND,          \
            TARGET_PRINT_OPERAND_ADDRESS, TARGET_PRINT_OPERAND_PUNCT_VALID_P,  \
            TARGET_MANGLE_ASSEMBLER_NAME,                                      \
    }

#define TARGET_SCHED                                                           \
    {                                                                          \
        TARGET_SCHED_ADJUST_COST, TARGET_SCHED_ADJUST_PRIORITY,                \
            TARGET_SCHED_ISSUE_RATE, TARGET_SCHED_VARIABLE_ISSUE,              \
            TARGET_SCHED_INIT, TARGET_SCHED_FINISH, TARGET_SCHED_INIT_GLOBAL,  \
            TARGET_SCHED_FINISH_GLOBAL, TARGET_SCHED_REORDER,                  \
            TARGET_SCHED_REORDER2, TARGET_SCHED_MACRO_FUSION_P,                \
            TARGET_SCHED_MACRO_FUSION_PAIR_P,                                  \
            TARGET_SCHED_DEPENDENCIES_EVALUATION_HOOK,                         \
            TARGET_SCHED_INIT_DFA_PRE_CYCLE_INSN,                              \
            TARGET_SCHED_DFA_PRE_CYCLE_INSN,                                   \
            TARGET_SCHED_INIT_DFA_POST_CYCLE_INSN,                             \
            TARGET_SCHED_DFA_POST_CYCLE_INSN,                                  \
            TARGET_SCHED_DFA_PRE_ADVANCE_CYCLE,                                \
            TARGET_SCHED_DFA_POST_ADVANCE_CYCLE,                               \
            TARGET_SCHED_FIRST_CYCLE_MULTIPASS_DFA_LOOKAHEAD,                  \
            TARGET_SCHED_FIRST_CYCLE_MULTIPASS_DFA_LOOKAHEAD_GUARD,            \
            TARGET_SCHED_FIRST_CYCLE_MULTIPASS_BEGIN,                          \
            TARGET_SCHED_FIRST_CYCLE_MULTIPASS_ISSUE,                          \
            TARGET_SCHED_FIRST_CYCLE_MULTIPASS_BACKTRACK,                      \
            TARGET_SCHED_FIRST_CYCLE_MULTIPASS_END,                            \
            TARGET_SCHED_FIRST_CYCLE_MULTIPASS_INIT,                           \
            TARGET_SCHED_FIRST_CYCLE_MULTIPASS_FINI,                           \
            TARGET_SCHED_DFA_NEW_CYCLE, TARGET_SCHED_IS_COSTLY_DEPENDENCE,     \
            TARGET_SCHED_H_I_D_EXTENDED, TARGET_SCHED_ALLOC_SCHED_CONTEXT,     \
            TARGET_SCHED_INIT_SCHED_CONTEXT, TARGET_SCHED_SET_SCHED_CONTEXT,   \
            TARGET_SCHED_CLEAR_SCHED_CONTEXT, TARGET_SCHED_FREE_SCHED_CONTEXT, \
            TARGET_SCHED_SPECULATE_INSN, TARGET_SCHED_NEEDS_BLOCK_P,           \
            TARGET_SCHED_GEN_SPEC_CHECK, TARGET_SCHED_SET_SCHED_FLAGS,         \
            TARGET_SCHED_GET_INSN_SPEC_DS, TARGET_SCHED_GET_INSN_CHECKED_DS,   \
            TARGET_SCHED_CAN_SPECULATE_INSN, TARGET_SCHED_SKIP_RTX_P,          \
            TARGET_SCHED_SMS_RES_MII, TARGET_SCHED_DISPATCH_DO,                \
            TARGET_SCHED_DISPATCH, TARGET_SCHED_EXPOSED_PIPELINE,              \
            TARGET_SCHED_REASSOCIATION_WIDTH, TARGET_SCHED_FUSION_PRIORITY,    \
    }

#define TARGET_SIMD_CLONE                                                      \
    {                                                                          \
        TARGET_SIMD_CLONE_COMPUTE_VECSIZE_AND_SIMDLEN,                         \
            TARGET_SIMD_CLONE_ADJUST, TARGET_SIMD_CLONE_USABLE,                \
    }

#define TARGET_SIMT                                                            \
    {                                                                          \
        TARGET_SIMT_VF,                                                        \
    }

#define TARGET_GOACC                                                           \
    {                                                                          \
        TARGET_GOACC_VALIDATE_DIMS, TARGET_GOACC_DIM_LIMIT,                    \
            TARGET_GOACC_FORK_JOIN, TARGET_GOACC_REDUCTION,                    \
    }

#define TARGET_VECTORIZE                                                       \
    {                                                                          \
        TARGET_VECTORIZE_BUILTIN_MASK_FOR_LOAD,                                \
            TARGET_VECTORIZE_BUILTIN_VECTORIZED_FUNCTION,                      \
            TARGET_VECTORIZE_BUILTIN_MD_VECTORIZED_FUNCTION,                   \
            TARGET_VECTORIZE_BUILTIN_CONVERSION,                               \
            TARGET_VECTORIZE_BUILTIN_VECTORIZATION_COST,                       \
            TARGET_VECTORIZE_PREFERRED_VECTOR_ALIGNMENT,                       \
            TARGET_VECTORIZE_VECTOR_ALIGNMENT_REACHABLE,                       \
            TARGET_VECTORIZE_VEC_PERM_CONST,                                   \
            TARGET_VECTORIZE_SUPPORT_VECTOR_MISALIGNMENT,                      \
            TARGET_VECTORIZE_PREFERRED_SIMD_MODE,                              \
            TARGET_VECTORIZE_SPLIT_REDUCTION,                                  \
            TARGET_VECTORIZE_AUTOVECTORIZE_VECTOR_SIZES,                       \
            TARGET_VECTORIZE_GET_MASK_MODE,                                    \
            TARGET_VECTORIZE_EMPTY_MASK_IS_EXPENSIVE,                          \
            TARGET_VECTORIZE_BUILTIN_GATHER, TARGET_VECTORIZE_BUILTIN_SCATTER, \
            TARGET_VECTORIZE_INIT_COST, TARGET_VECTORIZE_ADD_STMT_COST,        \
            TARGET_VECTORIZE_FINISH_COST, TARGET_VECTORIZE_DESTROY_COST_DATA,  \
    }

#define TARGET_ADDR_SPACE_HOOKS                                                \
    {                                                                          \
        TARGET_ADDR_SPACE_POINTER_MODE, TARGET_ADDR_SPACE_ADDRESS_MODE,        \
            TARGET_ADDR_SPACE_VALID_POINTER_MODE,                              \
            TARGET_ADDR_SPACE_LEGITIMATE_ADDRESS_P,                            \
            TARGET_ADDR_SPACE_LEGITIMIZE_ADDRESS, TARGET_ADDR_SPACE_SUBSET_P,  \
            TARGET_ADDR_SPACE_ZERO_ADDRESS_VALID, TARGET_ADDR_SPACE_CONVERT,   \
            TARGET_ADDR_SPACE_DEBUG, TARGET_ADDR_SPACE_DIAGNOSE_USAGE,         \
    }

#define TARGET_CALLS                                                           \
    {                                                                          \
        TARGET_PROMOTE_FUNCTION_MODE, TARGET_PROMOTE_PROTOTYPES,               \
            TARGET_STRUCT_VALUE_RTX, TARGET_OMIT_STRUCT_RETURN_REG,            \
            TARGET_RETURN_IN_MEMORY, TARGET_RETURN_IN_MSB,                     \
            TARGET_PASS_BY_REFERENCE, TARGET_EXPAND_BUILTIN_SAVEREGS,          \
            TARGET_SETUP_INCOMING_VARARGS, TARGET_LOAD_BOUNDS_FOR_ARG,         \
            TARGET_STORE_BOUNDS_FOR_ARG, TARGET_LOAD_RETURNED_BOUNDS,          \
            TARGET_STORE_RETURNED_BOUNDS, TARGET_SETUP_INCOMING_VARARG_BOUNDS, \
            TARGET_CALL_ARGS, TARGET_END_CALL_ARGS,                            \
            TARGET_STRICT_ARGUMENT_NAMING,                                     \
            TARGET_PRETEND_OUTGOING_VARARGS_NAMED, TARGET_SPLIT_COMPLEX_ARG,   \
            TARGET_MUST_PASS_IN_STACK, TARGET_CALLEE_COPIES,                   \
            TARGET_ARG_PARTIAL_BYTES, TARGET_FUNCTION_ARG_ADVANCE,             \
            TARGET_FUNCTION_ARG_OFFSET, TARGET_FUNCTION_ARG_PADDING,           \
            TARGET_FUNCTION_ARG, TARGET_FUNCTION_INCOMING_ARG,                 \
            TARGET_FUNCTION_ARG_BOUNDARY, TARGET_FUNCTION_ARG_ROUND_BOUNDARY,  \
            TARGET_INVALID_ARG_FOR_UNPROTOTYPED_FN, TARGET_FUNCTION_VALUE,     \
            TARGET_LIBCALL_VALUE, TARGET_FUNCTION_VALUE_REGNO_P,               \
            TARGET_INTERNAL_ARG_POINTER, TARGET_UPDATE_STACK_BOUNDARY,         \
            TARGET_GET_DRAP_RTX, TARGET_ALLOCATE_STACK_SLOTS_FOR_ARGS,         \
            TARGET_STATIC_CHAIN, TARGET_TRAMPOLINE_INIT,                       \
            TARGET_TRAMPOLINE_ADJUST_ADDRESS,                                  \
            TARGET_CUSTOM_FUNCTION_DESCRIPTORS, TARGET_RETURN_POPS_ARGS,       \
            TARGET_GET_RAW_RESULT_MODE, TARGET_GET_RAW_ARG_MODE,               \
            TARGET_EMPTY_RECORD_P, TARGET_WARN_PARAMETER_PASSING_ABI,          \
    }

#define TARGET_C                                                               \
    {                                                                          \
        TARGET_C_MODE_FOR_SUFFIX, TARGET_C_EXCESS_PRECISION,                   \
    }

#define TARGET_CXX                                                             \
    {                                                                          \
        TARGET_CXX_GUARD_TYPE, TARGET_CXX_GUARD_MASK_BIT,                      \
            TARGET_CXX_GET_COOKIE_SIZE, TARGET_CXX_COOKIE_HAS_SIZE,            \
            TARGET_CXX_IMPORT_EXPORT_CLASS, TARGET_CXX_CDTOR_RETURNS_THIS,     \
            TARGET_CXX_KEY_METHOD_MAY_BE_INLINE,                               \
            TARGET_CXX_DETERMINE_CLASS_DATA_VISIBILITY,                        \
            TARGET_CXX_CLASS_DATA_ALWAYS_COMDAT,                               \
            TARGET_CXX_LIBRARY_RTTI_COMDAT, TARGET_CXX_USE_AEABI_ATEXIT,       \
            TARGET_CXX_USE_ATEXIT_FOR_CXA_ATEXIT,                              \
            TARGET_CXX_ADJUST_CLASS_AT_DEFINITION,                             \
            TARGET_CXX_DECL_MANGLING_CONTEXT,                                  \
    }

#define TARGET_EMUTLS                                                          \
    {                                                                          \
        TARGET_EMUTLS_GET_ADDRESS, TARGET_EMUTLS_REGISTER_COMMON,              \
            TARGET_EMUTLS_VAR_SECTION, TARGET_EMUTLS_TMPL_SECTION,             \
            TARGET_EMUTLS_VAR_PREFIX, TARGET_EMUTLS_TMPL_PREFIX,               \
            TARGET_EMUTLS_VAR_FIELDS, TARGET_EMUTLS_VAR_INIT,                  \
            TARGET_EMUTLS_VAR_ALIGN_FIXED,                                     \
            TARGET_EMUTLS_DEBUG_FORM_TLS_ADDRESS,                              \
    }

#define TARGET_OPTION_HOOKS                                                    \
    {                                                                          \
        TARGET_OPTION_VALID_ATTRIBUTE_P, TARGET_OPTION_SAVE,                   \
            TARGET_OPTION_RESTORE, TARGET_OPTION_POST_STREAM_IN,               \
            TARGET_OPTION_PRINT, TARGET_OPTION_PRAGMA_PARSE,                   \
            TARGET_OPTION_OVERRIDE, TARGET_OPTION_FUNCTION_VERSIONS,           \
            TARGET_CAN_INLINE_P, TARGET_RELAYOUT_FUNCTION,                     \
    }

#define TARGET_SHRINK_WRAP_HOOKS                                               \
    {                                                                          \
        TARGET_SHRINK_WRAP_GET_SEPARATE_COMPONENTS,                            \
            TARGET_SHRINK_WRAP_COMPONENTS_FOR_BB,                              \
            TARGET_SHRINK_WRAP_DISQUALIFY_COMPONENTS,                          \
            TARGET_SHRINK_WRAP_EMIT_PROLOGUE_COMPONENTS,                       \
            TARGET_SHRINK_WRAP_EMIT_EPILOGUE_COMPONENTS,                       \
            TARGET_SHRINK_WRAP_SET_HANDLED_COMPONENTS,                         \
    }

#define TARGET_TOGGLE_                                                         \
    {                                                                          \
        TARGET_MODE_EMIT, TARGET_MODE_NEEDED, TARGET_MODE_AFTER,               \
            TARGET_MODE_ENTRY, TARGET_MODE_EXIT, TARGET_MODE_PRIORITY,         \
    }
