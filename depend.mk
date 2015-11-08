LINK_FLAGS += -lm
O_FILES += $(O_DIR)/srcs/anim/anim_start.o $(O_DIR)/srcs/anim/anim_update.o \
	$(O_DIR)/srcs/anim/smooth_back_in.o \
	$(O_DIR)/srcs/anim/smooth_back_in_out.o \
	$(O_DIR)/srcs/anim/smooth_back_out.o $(O_DIR)/srcs/anim/smooth_bounce.o \
	$(O_DIR)/srcs/anim/smooth_elastic.o $(O_DIR)/srcs/anim/smooth_in.o \
	$(O_DIR)/srcs/anim/smooth_in_out.o $(O_DIR)/srcs/anim/smooth_linear.o \
	$(O_DIR)/srcs/anim/smooth_out.o $(O_DIR)/srcs/camera/camera_get_view.o \
	$(O_DIR)/srcs/camera/camera_look.o $(O_DIR)/srcs/camera/camera_move.o \
	$(O_DIR)/srcs/events/events.o $(O_DIR)/libft/ft_base/ft_abs.o \
	$(O_DIR)/libft/ft_base/ft_atoib.o $(O_DIR)/libft/ft_base/ft_escape.o \
	$(O_DIR)/libft/ft_base/ft_is.o $(O_DIR)/libft/ft_base/ft_max.o \
	$(O_DIR)/libft/ft_base/ft_min.o $(O_DIR)/libft/ft_base/ft_strchri.o \
	$(O_DIR)/libft/ft_base/ft_strlen.o $(O_DIR)/libft/ft_base/ft_unescape.o \
	$(O_DIR)/libft/ft_base/mem/ft_bzero.o \
	$(O_DIR)/libft/ft_base/mem/ft_emalloc.o \
	$(O_DIR)/libft/ft_base/mem/ft_memcmp.o \
	$(O_DIR)/libft/ft_base/mem/ft_memcpy.o \
	$(O_DIR)/libft/ft_base/mem/ft_memdup.o \
	$(O_DIR)/libft/ft_base/mem/ft_memfill.o \
	$(O_DIR)/libft/ft_base/mem/ft_memmove.o \
	$(O_DIR)/libft/ft_base/mem/ft_memrcpy.o \
	$(O_DIR)/libft/ft_base/mem/ft_memset.o \
	$(O_DIR)/libft/ft_base/mem/ft_memstart.o \
	$(O_DIR)/libft/ft_base/mem/ft_memswap.o \
	$(O_DIR)/libft/ft_base/misc/ft_clock.o \
	$(O_DIR)/libft/ft_base/misc/ft_nanoclock.o \
	$(O_DIR)/libft/ft_base/misc/ft_rand.o \
	$(O_DIR)/libft/ft_base/misc/ft_randbool.o \
	$(O_DIR)/libft/ft_base/sub/ft_sub.o $(O_DIR)/libft/ft_base/sub/ft_subchr.o \
	$(O_DIR)/libft/ft_base/sub/ft_subcount.o \
	$(O_DIR)/libft/ft_base/sub/ft_subequ.o \
	$(O_DIR)/libft/ft_base/sub/ft_subextract.o \
	$(O_DIR)/libft/ft_base/sub/ft_subfloat.o \
	$(O_DIR)/libft/ft_base/sub/ft_subindex.o \
	$(O_DIR)/libft/ft_base/sub/ft_subint.o \
	$(O_DIR)/libft/ft_base/sub/ft_subnext.o \
	$(O_DIR)/libft/ft_base/sub/ft_subnextc.o \
	$(O_DIR)/libft/ft_base/sub/ft_subsub.o \
	$(O_DIR)/libft/ft_base/sub/ft_subtrim.o \
	$(O_DIR)/libft/ft_base/sub/ft_subtriml.o \
	$(O_DIR)/libft/ft_base/sub/ft_subtrimr.o \
	$(O_DIR)/libft/ft_base/wchar/ft_widetoa.o \
	$(O_DIR)/libft/ft_base/wchar/ft_wstrconv.o \
	$(O_DIR)/libft/ft_base/wchar/ft_wstrlen.o \
	$(O_DIR)/libft/ft_base/wchar/ft_wstrnconv.o \
	$(O_DIR)/libft/ft_buff/ft_buffclear.o $(O_DIR)/libft/ft_buff/ft_buffget.o \
	$(O_DIR)/libft/ft_buff/ft_parse.o $(O_DIR)/libft/ft_buff/ft_parsebase.o \
	$(O_DIR)/libft/ft_buff/ft_parsedouble.o \
	$(O_DIR)/libft/ft_buff/ft_parseendl.o $(O_DIR)/libft/ft_buff/ft_parsef.o \
	$(O_DIR)/libft/ft_buff/ft_parseint.o $(O_DIR)/libft/ft_buff/ft_parselong.o \
	$(O_DIR)/libft/ft_buff/ft_parsen.o $(O_DIR)/libft/ft_buff/ft_parsenot.o \
	$(O_DIR)/libft/ft_buff/ft_parsespace.o \
	$(O_DIR)/libft/ft_buff/ft_parsestr.o \
	$(O_DIR)/libft/ft_buff/ft_parsewhite.o \
	$(O_DIR)/libft/ft_buff/ft_readbuff.o $(O_DIR)/libft/ft_dstr/ft_dstradd.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrclear.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrextend.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrspan.o \
	$(O_DIR)/libft/get_next_line/get_next_line.o \
	$(O_DIR)/libft/ft_hmap/ft_djb2.o $(O_DIR)/libft/ft_hmap/ft_hmapdatas.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapdestroy.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapget.o $(O_DIR)/libft/ft_hmap/ft_hmapkeys.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapnew.o $(O_DIR)/libft/ft_hmap/ft_hmapput.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapputp.o $(O_DIR)/libft/ft_hmap/ft_hmaprem.o \
	$(O_DIR)/libft/ft_hmap/hmap_puth.o $(O_DIR)/libft/ft_list/ft_listadd.o \
	$(O_DIR)/libft/ft_list/ft_listremove.o \
	$(O_DIR)/libft/ft_list/ft_listsort.o $(O_DIR)/libft/ft_out/ft_flush.o \
	$(O_DIR)/libft/ft_out/ft_hexdump.o $(O_DIR)/libft/ft_out/ft_out.o \
	$(O_DIR)/libft/ft_out/ft_write.o $(O_DIR)/libft/ft_out/ft_writebase.o \
	$(O_DIR)/libft/ft_out/ft_writechar.o \
	$(O_DIR)/libft/ft_out/ft_writedouble.o $(O_DIR)/libft/ft_out/ft_writeint.o \
	$(O_DIR)/libft/ft_out/ft_writenchar.o $(O_DIR)/libft/ft_out/ft_writenl.o \
	$(O_DIR)/libft/ft_out/ft_writestr.o $(O_DIR)/libft/ft_printf/args_utils.o \
	$(O_DIR)/libft/ft_printf/flags/flag_b.o \
	$(O_DIR)/libft/ft_printf/flags/flag_c.o \
	$(O_DIR)/libft/ft_printf/flags/flag_d.o \
	$(O_DIR)/libft/ft_printf/flags/flag_f.o \
	$(O_DIR)/libft/ft_printf/flags/flag_n.o \
	$(O_DIR)/libft/ft_printf/flags/flag_o.o \
	$(O_DIR)/libft/ft_printf/flags/flag_other.o \
	$(O_DIR)/libft/ft_printf/flags/flag_p.o \
	$(O_DIR)/libft/ft_printf/flags/flag_percent.o \
	$(O_DIR)/libft/ft_printf/flags/flag_r.o \
	$(O_DIR)/libft/ft_printf/flags/flag_rr.o \
	$(O_DIR)/libft/ft_printf/flags/flag_s.o \
	$(O_DIR)/libft/ft_printf/flags/flag_u.o \
	$(O_DIR)/libft/ft_printf/flags/flag_w.o \
	$(O_DIR)/libft/ft_printf/flags/flag_x.o \
	$(O_DIR)/libft/ft_printf/flags_utils.o \
	$(O_DIR)/libft/ft_printf/ft_aprintf.o \
	$(O_DIR)/libft/ft_printf/ft_asprintf.o \
	$(O_DIR)/libft/ft_printf/ft_fdprintf.o \
	$(O_DIR)/libft/ft_printf/ft_printf.o \
	$(O_DIR)/libft/ft_printf/ft_snprintf.o \
	$(O_DIR)/libft/ft_printf/ft_sprintf.o $(O_DIR)/libft/ft_printf/ft_writef.o \
	$(O_DIR)/libft/ft_printf/metas/meta_fl.o \
	$(O_DIR)/libft/ft_printf/metas/meta_nl.o \
	$(O_DIR)/libft/ft_printf/metas_utils.o \
	$(O_DIR)/libft/ft_printf/parse_format.o \
	$(O_DIR)/libft/ft_printf/parse_meta.o $(O_DIR)/libft/ft_printf/writef.o \
	$(O_DIR)/libft/ft_vector/ft_vclear.o \
	$(O_DIR)/libft/ft_vector/ft_vpush_back.o \
	$(O_DIR)/libft/ft_vector/ft_vremove.o \
	$(O_DIR)/libft/ft_vector/ft_vreserve.o $(O_DIR)/srcs/main/callbacks.o \
	$(O_DIR)/srcs/main/init_window.o $(O_DIR)/srcs/main/main.o \
	$(O_DIR)/srcs/main/motions.o $(O_DIR)/srcs/math_utils/ft_mat4look_at.o \
	$(O_DIR)/srcs/math_utils/ft_mat4mult.o \
	$(O_DIR)/srcs/math_utils/ft_mat4perspective.o \
	$(O_DIR)/srcs/math_utils/ft_mat4reflect.o \
	$(O_DIR)/srcs/math_utils/ft_mat4rotate.o \
	$(O_DIR)/srcs/math_utils/ft_mat4scale.o \
	$(O_DIR)/srcs/math_utils/ft_mat4shear.o \
	$(O_DIR)/srcs/math_utils/ft_mat4translate.o \
	$(O_DIR)/srcs/math_utils/ft_mat4transpose.o \
	$(O_DIR)/srcs/math_utils/ft_vec3cross.o \
	$(O_DIR)/srcs/math_utils/ft_vec3dot.o \
	$(O_DIR)/srcs/math_utils/ft_vec3front.o \
	$(O_DIR)/srcs/math_utils/ft_vec3norm.o \
	$(O_DIR)/srcs/math_utils/ft_vec3rotate.o \
	$(O_DIR)/srcs/math_utils/ft_vec3sub.o \
	$(O_DIR)/srcs/mesh_loader/build_mesh.o \
	$(O_DIR)/srcs/mesh_loader/build_mtl.o \
	$(O_DIR)/srcs/mesh_loader/load_mesh.o \
	$(O_DIR)/srcs/mesh_loader/parse_mesh.o \
	$(O_DIR)/srcs/mesh_loader/parse_mesh_tokens.o \
	$(O_DIR)/srcs/mesh_loader/parse_mesh_tokens_mtl.o \
	$(O_DIR)/srcs/mesh_loader/send_mesh.o $(O_DIR)/srcs/mtl_loader/load_mtl.o \
	$(O_DIR)/srcs/mtl_loader/parse_mtl.o \
	$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens.o \
	$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens_map.o \
	$(O_DIR)/srcs/obj_anim/anim_c_move.o $(O_DIR)/srcs/obj_anim/anim_c_rot.o \
	$(O_DIR)/srcs/obj_anim/anim_c_scale.o \
	$(O_DIR)/srcs/obj_anim/anim_c_shear.o \
	$(O_DIR)/srcs/renderer/depth_renderer.o $(O_DIR)/srcs/renderer/renderers.o \
	$(O_DIR)/srcs/renderer/simple_renderer.o \
	$(O_DIR)/srcs/shader_loader/compile_shader.o \
	$(O_DIR)/srcs/shader_loader/load_shader.o \
	$(O_DIR)/srcs/shader_loader/load_uniforms.o \
	$(O_DIR)/srcs/shader_loader/read_shader.o \
	$(O_DIR)/srcs/shader_loader/shader_get_uniform.o \
	$(O_DIR)/srcs/texture_loader/ft_loadimage.o \
	$(O_DIR)/srcs/texture_loader/load_texture.o \
	$(O_DIR)/srcs/texture_loader/tga_parser.o \
	$(O_DIR)/srcs/transform/ft_transform_get.o \
	$(O_DIR)/srcs/transform/ft_transform_move.o \
	$(O_DIR)/srcs/transform/ft_transform_reflect.o \
	$(O_DIR)/srcs/transform/ft_transform_rotate.o \
	$(O_DIR)/srcs/transform/ft_transform_scale.o \
	$(O_DIR)/srcs/transform/ft_transform_shear.o $(O_DIR)/srcs/utils/fps.o \
	$(O_DIR)/srcs/utils/ft_error.o $(O_DIR)/srcs/utils/ft_listremove_next.o \
	$(O_DIR)/srcs/utils/ft_subends.o $(O_DIR)/srcs/utils/ft_substart.o \
	$(O_DIR)/srcs/utils/parse_fvec.o

# module ft::hmap
$(O_DIR)/libft/ft_hmap/ft_djb2.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_hmap -Ilibft/ft_hmap/public
$(O_DIR)/libft/ft_hmap/ft_djb2.o: libft/ft_hmap/ft_djb2.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h | $(O_DIR)/libft/ft_hmap/
$(O_DIR)/libft/ft_hmap/ft_hmapdatas.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_hmap -Ilibft/ft_hmap/public
$(O_DIR)/libft/ft_hmap/ft_hmapdatas.o: libft/ft_hmap/ft_hmapdatas.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h | $(O_DIR)/libft/ft_hmap/
$(O_DIR)/libft/ft_hmap/ft_hmapdestroy.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_hmap -Ilibft/ft_hmap/public
$(O_DIR)/libft/ft_hmap/ft_hmapdestroy.o: libft/ft_hmap/ft_hmapdestroy.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h | $(O_DIR)/libft/ft_hmap/
$(O_DIR)/libft/ft_hmap/ft_hmapget.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_hmap -Ilibft/ft_hmap/public
$(O_DIR)/libft/ft_hmap/ft_hmapget.o: libft/ft_hmap/ft_hmapget.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h | $(O_DIR)/libft/ft_hmap/
$(O_DIR)/libft/ft_hmap/ft_hmapkeys.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_hmap -Ilibft/ft_hmap/public
$(O_DIR)/libft/ft_hmap/ft_hmapkeys.o: libft/ft_hmap/ft_hmapkeys.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h | $(O_DIR)/libft/ft_hmap/
$(O_DIR)/libft/ft_hmap/ft_hmapnew.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_hmap -Ilibft/ft_hmap/public
$(O_DIR)/libft/ft_hmap/ft_hmapnew.o: libft/ft_hmap/ft_hmapnew.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h | $(O_DIR)/libft/ft_hmap/
$(O_DIR)/libft/ft_hmap/ft_hmapput.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_hmap -Ilibft/ft_hmap/public
$(O_DIR)/libft/ft_hmap/ft_hmapput.o: libft/ft_hmap/ft_hmapput.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h | $(O_DIR)/libft/ft_hmap/
$(O_DIR)/libft/ft_hmap/ft_hmapputp.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_hmap -Ilibft/ft_hmap/public
$(O_DIR)/libft/ft_hmap/ft_hmapputp.o: libft/ft_hmap/ft_hmapputp.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h | $(O_DIR)/libft/ft_hmap/
$(O_DIR)/libft/ft_hmap/ft_hmaprem.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_hmap -Ilibft/ft_hmap/public
$(O_DIR)/libft/ft_hmap/ft_hmaprem.o: libft/ft_hmap/ft_hmaprem.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h | $(O_DIR)/libft/ft_hmap/
$(O_DIR)/libft/ft_hmap/hmap_puth.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_hmap -Ilibft/ft_hmap/public
$(O_DIR)/libft/ft_hmap/hmap_puth.o: libft/ft_hmap/hmap_puth.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h | $(O_DIR)/libft/ft_hmap/

# module mesh_loader
$(O_DIR)/srcs/mesh_loader/build_mesh.o: INCLUDE_FLAGS += -Isrcs/gl \
	-Ilibft/ft_base/public -Ilibft/ft_hmap -Ilibft/ft_hmap/public \
	-Ilibft/ft_vector/public -Ilibft/get_next_line/public \
	-Ilibft/ft_printf/public -Isrcs/math_utils/include -Isrcs/utils/include \
	-Isrcs/mesh -Isrcs/mesh_loader/include -Isrcs/mesh_loader/include/public \
	-Isrcs/mtl -Isrcs/mtl_loader/include/public -Isrcs/texture
$(O_DIR)/srcs/mesh_loader/build_mesh.o: srcs/mesh_loader/build_mesh.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_vector/public/ft_vector.h srcs/math_utils/include/math_utils.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h \
	srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h srcs/utils/include/utils.h \
	| $(O_DIR)/srcs/mesh_loader/
$(O_DIR)/srcs/mesh_loader/build_mtl.o: INCLUDE_FLAGS += -Isrcs/gl \
	-Ilibft/ft_base/public -Ilibft/ft_hmap -Ilibft/ft_hmap/public \
	-Ilibft/ft_vector/public -Ilibft/get_next_line/public \
	-Ilibft/ft_printf/public -Isrcs/math_utils/include -Isrcs/utils/include \
	-Isrcs/mesh -Isrcs/mesh_loader/include -Isrcs/mesh_loader/include/public \
	-Isrcs/mtl -Isrcs/mtl_loader/include/public -Isrcs/texture
$(O_DIR)/srcs/mesh_loader/build_mtl.o: srcs/mesh_loader/build_mtl.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_vector/public/ft_vector.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h | $(O_DIR)/srcs/mesh_loader/
$(O_DIR)/srcs/mesh_loader/load_mesh.o: INCLUDE_FLAGS += -Isrcs/gl \
	-Ilibft/ft_base/public -Ilibft/ft_hmap -Ilibft/ft_hmap/public \
	-Ilibft/ft_vector/public -Ilibft/get_next_line/public \
	-Ilibft/ft_printf/public -Isrcs/math_utils/include -Isrcs/utils/include \
	-Isrcs/mesh -Isrcs/mesh_loader/include -Isrcs/mesh_loader/include/public \
	-Isrcs/mtl -Isrcs/mtl_loader/include/public -Isrcs/texture
$(O_DIR)/srcs/mesh_loader/load_mesh.o: srcs/mesh_loader/load_mesh.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_printf/public/ft_printf.h \
	libft/ft_vector/public/ft_vector.h srcs/math_utils/include/math_utils.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h \
	srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h | $(O_DIR)/srcs/mesh_loader/
$(O_DIR)/srcs/mesh_loader/parse_mesh.o: INCLUDE_FLAGS += -Isrcs/gl \
	-Ilibft/ft_base/public -Ilibft/ft_hmap -Ilibft/ft_hmap/public \
	-Ilibft/ft_vector/public -Ilibft/get_next_line/public \
	-Ilibft/ft_printf/public -Isrcs/math_utils/include -Isrcs/utils/include \
	-Isrcs/mesh -Isrcs/mesh_loader/include -Isrcs/mesh_loader/include/public \
	-Isrcs/mtl -Isrcs/mtl_loader/include/public -Isrcs/texture
$(O_DIR)/srcs/mesh_loader/parse_mesh.o: srcs/mesh_loader/parse_mesh.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_vector/public/ft_vector.h \
	libft/get_next_line/public/get_next_line.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h \
	srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h srcs/utils/include/utils.h \
	| $(O_DIR)/srcs/mesh_loader/
$(O_DIR)/srcs/mesh_loader/parse_mesh_tokens.o: INCLUDE_FLAGS += -Isrcs/gl \
	-Ilibft/ft_base/public -Ilibft/ft_hmap -Ilibft/ft_hmap/public \
	-Ilibft/ft_vector/public -Ilibft/get_next_line/public \
	-Ilibft/ft_printf/public -Isrcs/math_utils/include -Isrcs/utils/include \
	-Isrcs/mesh -Isrcs/mesh_loader/include -Isrcs/mesh_loader/include/public \
	-Isrcs/mtl -Isrcs/mtl_loader/include/public -Isrcs/texture
$(O_DIR)/srcs/mesh_loader/parse_mesh_tokens.o: \
	srcs/mesh_loader/parse_mesh_tokens.c libft/ft_base/public/libft.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_vector/public/ft_vector.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h \
	srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h srcs/utils/include/utils.h \
	| $(O_DIR)/srcs/mesh_loader/
$(O_DIR)/srcs/mesh_loader/parse_mesh_tokens_mtl.o: INCLUDE_FLAGS += -Isrcs/gl \
	-Ilibft/ft_base/public -Ilibft/ft_hmap -Ilibft/ft_hmap/public \
	-Ilibft/ft_vector/public -Ilibft/get_next_line/public \
	-Ilibft/ft_printf/public -Isrcs/math_utils/include -Isrcs/utils/include \
	-Isrcs/mesh -Isrcs/mesh_loader/include -Isrcs/mesh_loader/include/public \
	-Isrcs/mtl -Isrcs/mtl_loader/include/public -Isrcs/texture
$(O_DIR)/srcs/mesh_loader/parse_mesh_tokens_mtl.o: \
	srcs/mesh_loader/parse_mesh_tokens_mtl.c libft/ft_base/public/libft.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_vector/public/ft_vector.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/mtl_loader/include/public/mtl_loader.h srcs/texture/texture.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/mesh_loader/
$(O_DIR)/srcs/mesh_loader/send_mesh.o: INCLUDE_FLAGS += -Isrcs/gl \
	-Ilibft/ft_base/public -Ilibft/ft_hmap -Ilibft/ft_hmap/public \
	-Ilibft/ft_vector/public -Ilibft/get_next_line/public \
	-Ilibft/ft_printf/public -Isrcs/math_utils/include -Isrcs/utils/include \
	-Isrcs/mesh -Isrcs/mesh_loader/include -Isrcs/mesh_loader/include/public \
	-Isrcs/mtl -Isrcs/mtl_loader/include/public -Isrcs/texture
$(O_DIR)/srcs/mesh_loader/send_mesh.o: srcs/mesh_loader/send_mesh.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_vector/public/ft_vector.h srcs/gl/gl.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h \
	srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h | $(O_DIR)/srcs/mesh_loader/

# module utils
$(O_DIR)/srcs/utils/fps.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_list/public -Ilibft/ft_out/public -Ilibft/ft_printf/public \
	-Isrcs/utils/include
$(O_DIR)/srcs/utils/fps.o: srcs/utils/fps.c libft/ft_base/public/libft.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/utils/
$(O_DIR)/srcs/utils/ft_error.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_list/public -Ilibft/ft_out/public -Ilibft/ft_printf/public \
	-Isrcs/utils/include
$(O_DIR)/srcs/utils/ft_error.o: srcs/utils/ft_error.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/utils/
$(O_DIR)/srcs/utils/ft_listremove_next.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_list/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf/public -Isrcs/utils/include
$(O_DIR)/srcs/utils/ft_listremove_next.o: srcs/utils/ft_listremove_next.c \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/utils/
$(O_DIR)/srcs/utils/ft_subends.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_list/public -Ilibft/ft_out/public -Ilibft/ft_printf/public \
	-Isrcs/utils/include
$(O_DIR)/srcs/utils/ft_subends.o: srcs/utils/ft_subends.c \
	libft/ft_base/public/libft.h srcs/utils/include/utils.h \
	| $(O_DIR)/srcs/utils/
$(O_DIR)/srcs/utils/ft_substart.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_list/public -Ilibft/ft_out/public -Ilibft/ft_printf/public \
	-Isrcs/utils/include
$(O_DIR)/srcs/utils/ft_substart.o: srcs/utils/ft_substart.c \
	libft/ft_base/public/libft.h srcs/utils/include/utils.h \
	| $(O_DIR)/srcs/utils/
$(O_DIR)/srcs/utils/parse_fvec.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_list/public -Ilibft/ft_out/public -Ilibft/ft_printf/public \
	-Isrcs/utils/include
$(O_DIR)/srcs/utils/parse_fvec.o: srcs/utils/parse_fvec.c \
	libft/ft_base/public/libft.h libft/ft_printf/public/ft_printf.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/utils/

# module ft::base
$(O_DIR)/libft/ft_base/ft_abs.o: INCLUDE_FLAGS += -Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/ft_abs.o: libft/ft_base/ft_abs.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/
$(O_DIR)/libft/ft_base/ft_atoib.o: INCLUDE_FLAGS += -Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/ft_atoib.o: libft/ft_base/ft_atoib.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/
$(O_DIR)/libft/ft_base/ft_escape.o: INCLUDE_FLAGS += -Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/ft_escape.o: libft/ft_base/ft_escape.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/
$(O_DIR)/libft/ft_base/ft_is.o: INCLUDE_FLAGS += -Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/ft_is.o: libft/ft_base/ft_is.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/
$(O_DIR)/libft/ft_base/ft_max.o: INCLUDE_FLAGS += -Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/ft_max.o: libft/ft_base/ft_max.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/
$(O_DIR)/libft/ft_base/ft_min.o: INCLUDE_FLAGS += -Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/ft_min.o: libft/ft_base/ft_min.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/
$(O_DIR)/libft/ft_base/ft_strchri.o: INCLUDE_FLAGS += -Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/ft_strchri.o: libft/ft_base/ft_strchri.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/
$(O_DIR)/libft/ft_base/ft_strlen.o: INCLUDE_FLAGS += -Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/ft_strlen.o: libft/ft_base/ft_strlen.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/
$(O_DIR)/libft/ft_base/ft_unescape.o: INCLUDE_FLAGS += -Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/ft_unescape.o: libft/ft_base/ft_unescape.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/
$(O_DIR)/libft/ft_base/mem/ft_bzero.o: INCLUDE_FLAGS += -Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/mem/ft_bzero.o: libft/ft_base/mem/ft_bzero.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/mem/
$(O_DIR)/libft/ft_base/mem/ft_emalloc.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/mem/ft_emalloc.o: libft/ft_base/mem/ft_emalloc.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/mem/
$(O_DIR)/libft/ft_base/mem/ft_memcmp.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/mem/ft_memcmp.o: libft/ft_base/mem/ft_memcmp.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/mem/
$(O_DIR)/libft/ft_base/mem/ft_memcpy.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/mem/ft_memcpy.o: libft/ft_base/mem/ft_memcpy.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/mem/
$(O_DIR)/libft/ft_base/mem/ft_memdup.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/mem/ft_memdup.o: libft/ft_base/mem/ft_memdup.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/mem/
$(O_DIR)/libft/ft_base/mem/ft_memfill.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/mem/ft_memfill.o: libft/ft_base/mem/ft_memfill.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/mem/
$(O_DIR)/libft/ft_base/mem/ft_memmove.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/mem/ft_memmove.o: libft/ft_base/mem/ft_memmove.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/mem/
$(O_DIR)/libft/ft_base/mem/ft_memrcpy.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/mem/ft_memrcpy.o: libft/ft_base/mem/ft_memrcpy.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/mem/
$(O_DIR)/libft/ft_base/mem/ft_memset.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/mem/ft_memset.o: libft/ft_base/mem/ft_memset.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/mem/
$(O_DIR)/libft/ft_base/mem/ft_memstart.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/mem/ft_memstart.o: libft/ft_base/mem/ft_memstart.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/mem/
$(O_DIR)/libft/ft_base/mem/ft_memswap.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/mem/ft_memswap.o: libft/ft_base/mem/ft_memswap.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/mem/
$(O_DIR)/libft/ft_base/misc/ft_clock.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/misc/ft_clock.o: libft/ft_base/misc/ft_clock.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/misc/
$(O_DIR)/libft/ft_base/misc/ft_nanoclock.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/misc/ft_nanoclock.o: libft/ft_base/misc/ft_nanoclock.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/misc/
$(O_DIR)/libft/ft_base/misc/ft_rand.o: INCLUDE_FLAGS += -Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/misc/ft_rand.o: libft/ft_base/misc/ft_rand.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/misc/
$(O_DIR)/libft/ft_base/misc/ft_randbool.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/misc/ft_randbool.o: libft/ft_base/misc/ft_randbool.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/misc/
$(O_DIR)/libft/ft_base/sub/ft_sub.o: INCLUDE_FLAGS += -Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/sub/ft_sub.o: libft/ft_base/sub/ft_sub.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/sub/
$(O_DIR)/libft/ft_base/sub/ft_subchr.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/sub/ft_subchr.o: libft/ft_base/sub/ft_subchr.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/sub/
$(O_DIR)/libft/ft_base/sub/ft_subcount.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/sub/ft_subcount.o: libft/ft_base/sub/ft_subcount.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/sub/
$(O_DIR)/libft/ft_base/sub/ft_subequ.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/sub/ft_subequ.o: libft/ft_base/sub/ft_subequ.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/sub/
$(O_DIR)/libft/ft_base/sub/ft_subextract.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/sub/ft_subextract.o: libft/ft_base/sub/ft_subextract.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/sub/
$(O_DIR)/libft/ft_base/sub/ft_subfloat.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/sub/ft_subfloat.o: libft/ft_base/sub/ft_subfloat.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/sub/
$(O_DIR)/libft/ft_base/sub/ft_subindex.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/sub/ft_subindex.o: libft/ft_base/sub/ft_subindex.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/sub/
$(O_DIR)/libft/ft_base/sub/ft_subint.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/sub/ft_subint.o: libft/ft_base/sub/ft_subint.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/sub/
$(O_DIR)/libft/ft_base/sub/ft_subnext.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/sub/ft_subnext.o: libft/ft_base/sub/ft_subnext.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/sub/
$(O_DIR)/libft/ft_base/sub/ft_subnextc.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/sub/ft_subnextc.o: libft/ft_base/sub/ft_subnextc.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/sub/
$(O_DIR)/libft/ft_base/sub/ft_subsub.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/sub/ft_subsub.o: libft/ft_base/sub/ft_subsub.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/sub/
$(O_DIR)/libft/ft_base/sub/ft_subtrim.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/sub/ft_subtrim.o: libft/ft_base/sub/ft_subtrim.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/sub/
$(O_DIR)/libft/ft_base/sub/ft_subtriml.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/sub/ft_subtriml.o: libft/ft_base/sub/ft_subtriml.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/sub/
$(O_DIR)/libft/ft_base/sub/ft_subtrimr.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/sub/ft_subtrimr.o: libft/ft_base/sub/ft_subtrimr.c \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/sub/
$(O_DIR)/libft/ft_base/wchar/ft_widetoa.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/wchar/ft_widetoa.o: libft/ft_base/wchar/ft_widetoa.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h \
	| $(O_DIR)/libft/ft_base/wchar/
$(O_DIR)/libft/ft_base/wchar/ft_wstrconv.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/wchar/ft_wstrconv.o: libft/ft_base/wchar/ft_wstrconv.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h \
	| $(O_DIR)/libft/ft_base/wchar/
$(O_DIR)/libft/ft_base/wchar/ft_wstrlen.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/wchar/ft_wstrlen.o: libft/ft_base/wchar/ft_wstrlen.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h \
	| $(O_DIR)/libft/ft_base/wchar/
$(O_DIR)/libft/ft_base/wchar/ft_wstrnconv.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public
$(O_DIR)/libft/ft_base/wchar/ft_wstrnconv.o: \
	libft/ft_base/wchar/ft_wstrnconv.c libft/ft_base/public/ft_wchar.h \
	libft/ft_base/public/libft.h | $(O_DIR)/libft/ft_base/wchar/

# module mtl_loader
$(O_DIR)/srcs/mtl_loader/load_mtl.o: INCLUDE_FLAGS += \
	-Isrcs/texture_loader/include/public -Ilibft/ft_base/public \
	-Ilibft/ft_hmap -Ilibft/ft_hmap/public -Ilibft/ft_list/public \
	-Ilibft/ft_out/public -Ilibft/get_next_line/public \
	-Ilibft/ft_printf/public -Isrcs/math_utils/include -Isrcs/utils/include \
	-Isrcs/mtl -Isrcs/mtl_loader/include -Isrcs/mtl_loader/include/public \
	-Isrcs/texture
$(O_DIR)/srcs/mtl_loader/load_mtl.o: srcs/mtl_loader/load_mtl.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_printf/public/ft_printf.h \
	srcs/math_utils/include/math_utils.h srcs/mtl/mtl.h \
	srcs/mtl_loader/include/internal.h \
	srcs/mtl_loader/include/public/mtl_loader.h srcs/texture/texture.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/mtl_loader/
$(O_DIR)/srcs/mtl_loader/parse_mtl.o: INCLUDE_FLAGS += \
	-Isrcs/texture_loader/include/public -Ilibft/ft_base/public \
	-Ilibft/ft_hmap -Ilibft/ft_hmap/public -Ilibft/ft_list/public \
	-Ilibft/ft_out/public -Ilibft/get_next_line/public \
	-Ilibft/ft_printf/public -Isrcs/math_utils/include -Isrcs/utils/include \
	-Isrcs/mtl -Isrcs/mtl_loader/include -Isrcs/mtl_loader/include/public \
	-Isrcs/texture
$(O_DIR)/srcs/mtl_loader/parse_mtl.o: srcs/mtl_loader/parse_mtl.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_hmap/public/ft_hmap.h libft/get_next_line/public/get_next_line.h \
	srcs/math_utils/include/math_utils.h srcs/mtl/mtl.h \
	srcs/mtl_loader/include/internal.h \
	srcs/mtl_loader/include/public/mtl_loader.h srcs/texture/texture.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/mtl_loader/
$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens.o: INCLUDE_FLAGS += \
	-Isrcs/texture_loader/include/public -Ilibft/ft_base/public \
	-Ilibft/ft_hmap -Ilibft/ft_hmap/public -Ilibft/ft_list/public \
	-Ilibft/ft_out/public -Ilibft/get_next_line/public \
	-Ilibft/ft_printf/public -Isrcs/math_utils/include -Isrcs/utils/include \
	-Isrcs/mtl -Isrcs/mtl_loader/include -Isrcs/mtl_loader/include/public \
	-Isrcs/texture
$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens.o: \
	srcs/mtl_loader/parse_mtl_tokens.c libft/ft_base/public/libft.h \
	libft/ft_hmap/public/ft_hmap.h srcs/math_utils/include/math_utils.h \
	srcs/mtl/mtl.h srcs/mtl_loader/include/internal.h \
	srcs/mtl_loader/include/public/mtl_loader.h srcs/texture/texture.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/mtl_loader/
$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens_map.o: INCLUDE_FLAGS += \
	-Isrcs/texture_loader/include/public -Ilibft/ft_base/public \
	-Ilibft/ft_hmap -Ilibft/ft_hmap/public -Ilibft/ft_list/public \
	-Ilibft/ft_out/public -Ilibft/get_next_line/public \
	-Ilibft/ft_printf/public -Isrcs/math_utils/include -Isrcs/utils/include \
	-Isrcs/mtl -Isrcs/mtl_loader/include -Isrcs/mtl_loader/include/public \
	-Isrcs/texture
$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens_map.o: \
	srcs/mtl_loader/parse_mtl_tokens_map.c libft/ft_base/public/libft.h \
	libft/ft_hmap/public/ft_hmap.h srcs/math_utils/include/math_utils.h \
	srcs/mtl/mtl.h srcs/mtl_loader/include/internal.h \
	srcs/mtl_loader/include/public/mtl_loader.h srcs/texture/texture.h \
	srcs/texture_loader/include/public/texture_loader.h \
	| $(O_DIR)/srcs/mtl_loader/

# module renderer
$(O_DIR)/srcs/renderer/depth_renderer.o: INCLUDE_FLAGS += -Isrcs/gl \
	-Ilibft/ft_base/public -Ilibft/ft_hmap -Ilibft/ft_hmap/public \
	-Ilibft/ft_list/public -Ilibft/ft_out/public -Ilibft/ft_printf/public \
	-Isrcs/anim/include -Isrcs/camera/include -Isrcs/math_utils/include \
	-Isrcs/obj/include -Isrcs/renderer/include -Isrcs/renderer/include/public \
	-Isrcs/transform/include -Isrcs/utils/include -Isrcs/shader \
	-Isrcs/shader_loader/include/public -Isrcs/mesh -Isrcs/mtl -Isrcs/texture
$(O_DIR)/srcs/renderer/depth_renderer.o: srcs/renderer/depth_renderer.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/camera/include/camera.h srcs/gl/gl.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/renderer/include/public/renderer.h \
	srcs/renderer/include/renderers.h srcs/shader/shader.h \
	srcs/shader/shader.h srcs/shader_loader/include/public/shader_loader.h \
	srcs/texture/texture.h srcs/transform/include/transform.h \
	| $(O_DIR)/srcs/renderer/
$(O_DIR)/srcs/renderer/renderers.o: INCLUDE_FLAGS += -Isrcs/gl \
	-Ilibft/ft_base/public -Ilibft/ft_hmap -Ilibft/ft_hmap/public \
	-Ilibft/ft_list/public -Ilibft/ft_out/public -Ilibft/ft_printf/public \
	-Isrcs/anim/include -Isrcs/camera/include -Isrcs/math_utils/include \
	-Isrcs/obj/include -Isrcs/renderer/include -Isrcs/renderer/include/public \
	-Isrcs/transform/include -Isrcs/utils/include -Isrcs/shader \
	-Isrcs/shader_loader/include/public -Isrcs/mesh -Isrcs/mtl -Isrcs/texture
$(O_DIR)/srcs/renderer/renderers.o: srcs/renderer/renderers.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mtl/mtl.h srcs/obj/include/obj.h \
	srcs/renderer/include/public/renderer.h srcs/renderer/include/renderers.h \
	srcs/texture/texture.h srcs/transform/include/transform.h \
	| $(O_DIR)/srcs/renderer/
$(O_DIR)/srcs/renderer/simple_renderer.o: INCLUDE_FLAGS += -Isrcs/gl \
	-Ilibft/ft_base/public -Ilibft/ft_hmap -Ilibft/ft_hmap/public \
	-Ilibft/ft_list/public -Ilibft/ft_out/public -Ilibft/ft_printf/public \
	-Isrcs/anim/include -Isrcs/camera/include -Isrcs/math_utils/include \
	-Isrcs/obj/include -Isrcs/renderer/include -Isrcs/renderer/include/public \
	-Isrcs/transform/include -Isrcs/utils/include -Isrcs/shader \
	-Isrcs/shader_loader/include/public -Isrcs/mesh -Isrcs/mtl -Isrcs/texture
$(O_DIR)/srcs/renderer/simple_renderer.o: srcs/renderer/simple_renderer.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	srcs/anim/include/anim.h srcs/camera/include/camera.h \
	srcs/camera/include/camera.h srcs/gl/gl.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h srcs/mesh/mesh.h \
	srcs/mtl/mtl.h srcs/mtl/mtl.h srcs/obj/include/obj.h \
	srcs/obj/include/obj.h srcs/renderer/include/public/renderer.h \
	srcs/shader/shader.h srcs/shader_loader/include/public/shader_loader.h \
	srcs/texture/texture.h srcs/texture/texture.h \
	srcs/transform/include/transform.h srcs/utils/include/utils.h \
	| $(O_DIR)/srcs/renderer/

# module events
$(O_DIR)/srcs/events/events.o: INCLUDE_FLAGS += -Isrcs/gl \
	-Ilibft/ft_base/public -Ilibft/ft_list/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf/public -Isrcs/events/include -Isrcs/utils/include
$(O_DIR)/srcs/events/events.o: srcs/events/events.c \
	libft/ft_base/public/libft.h srcs/events/include/events.h srcs/gl/gl.h \
	srcs/gl/gl.h srcs/utils/include/utils.h | $(O_DIR)/srcs/events/

# module gl
ifeq ($(shell uname),Darwin)
BASE_FLAGS += -DMAC_OS_MODE=1
LINK_FLAGS += -lglfw3 -framework OpenGL
else
LINK_FLAGS += -lglfw -lGL -lGLEW
endif

# module ft::buff
$(O_DIR)/libft/ft_buff/ft_buffclear.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_buff/public
$(O_DIR)/libft/ft_buff/ft_buffclear.o: libft/ft_buff/ft_buffclear.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h \
	| $(O_DIR)/libft/ft_buff/
$(O_DIR)/libft/ft_buff/ft_buffget.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_buff/public
$(O_DIR)/libft/ft_buff/ft_buffget.o: libft/ft_buff/ft_buffget.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h \
	| $(O_DIR)/libft/ft_buff/
$(O_DIR)/libft/ft_buff/ft_parse.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_buff/public
$(O_DIR)/libft/ft_buff/ft_parse.o: libft/ft_buff/ft_parse.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h \
	| $(O_DIR)/libft/ft_buff/
$(O_DIR)/libft/ft_buff/ft_parsebase.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_buff/public
$(O_DIR)/libft/ft_buff/ft_parsebase.o: libft/ft_buff/ft_parsebase.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h \
	| $(O_DIR)/libft/ft_buff/
$(O_DIR)/libft/ft_buff/ft_parsedouble.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_buff/public
$(O_DIR)/libft/ft_buff/ft_parsedouble.o: libft/ft_buff/ft_parsedouble.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h \
	| $(O_DIR)/libft/ft_buff/
$(O_DIR)/libft/ft_buff/ft_parseendl.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_buff/public
$(O_DIR)/libft/ft_buff/ft_parseendl.o: libft/ft_buff/ft_parseendl.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h \
	| $(O_DIR)/libft/ft_buff/
$(O_DIR)/libft/ft_buff/ft_parsef.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_buff/public
$(O_DIR)/libft/ft_buff/ft_parsef.o: libft/ft_buff/ft_parsef.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h \
	| $(O_DIR)/libft/ft_buff/
$(O_DIR)/libft/ft_buff/ft_parseint.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_buff/public
$(O_DIR)/libft/ft_buff/ft_parseint.o: libft/ft_buff/ft_parseint.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h \
	| $(O_DIR)/libft/ft_buff/
$(O_DIR)/libft/ft_buff/ft_parselong.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_buff/public
$(O_DIR)/libft/ft_buff/ft_parselong.o: libft/ft_buff/ft_parselong.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h \
	| $(O_DIR)/libft/ft_buff/
$(O_DIR)/libft/ft_buff/ft_parsen.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_buff/public
$(O_DIR)/libft/ft_buff/ft_parsen.o: libft/ft_buff/ft_parsen.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h \
	| $(O_DIR)/libft/ft_buff/
$(O_DIR)/libft/ft_buff/ft_parsenot.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_buff/public
$(O_DIR)/libft/ft_buff/ft_parsenot.o: libft/ft_buff/ft_parsenot.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h \
	| $(O_DIR)/libft/ft_buff/
$(O_DIR)/libft/ft_buff/ft_parsespace.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_buff/public
$(O_DIR)/libft/ft_buff/ft_parsespace.o: libft/ft_buff/ft_parsespace.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h \
	| $(O_DIR)/libft/ft_buff/
$(O_DIR)/libft/ft_buff/ft_parsestr.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_buff/public
$(O_DIR)/libft/ft_buff/ft_parsestr.o: libft/ft_buff/ft_parsestr.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h \
	| $(O_DIR)/libft/ft_buff/
$(O_DIR)/libft/ft_buff/ft_parsewhite.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_buff/public
$(O_DIR)/libft/ft_buff/ft_parsewhite.o: libft/ft_buff/ft_parsewhite.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h \
	| $(O_DIR)/libft/ft_buff/
$(O_DIR)/libft/ft_buff/ft_readbuff.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_buff/public
$(O_DIR)/libft/ft_buff/ft_readbuff.o: libft/ft_buff/ft_readbuff.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h \
	| $(O_DIR)/libft/ft_buff/

# module shader_loader
$(O_DIR)/srcs/shader_loader/compile_shader.o: INCLUDE_FLAGS += -Isrcs/gl \
	-Ilibft/ft_base/public -Ilibft/ft_hmap -Ilibft/ft_hmap/public \
	-Ilibft/ft_list/public -Ilibft/ft_out/public -Ilibft/get_next_line/public \
	-Ilibft/ft_printf/public -Isrcs/utils/include -Isrcs/shader \
	-Isrcs/shader_loader/include -Isrcs/shader_loader/include/public
$(O_DIR)/srcs/shader_loader/compile_shader.o: \
	srcs/shader_loader/compile_shader.c libft/ft_base/public/ft_colors.h \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h \
	libft/ft_printf/public/ft_printf.h srcs/gl/gl.h srcs/shader/shader.h \
	srcs/shader_loader/include/internal.h \
	srcs/shader_loader/include/public/shader_loader.h \
	| $(O_DIR)/srcs/shader_loader/
$(O_DIR)/srcs/shader_loader/load_shader.o: INCLUDE_FLAGS += -Isrcs/gl \
	-Ilibft/ft_base/public -Ilibft/ft_hmap -Ilibft/ft_hmap/public \
	-Ilibft/ft_list/public -Ilibft/ft_out/public -Ilibft/get_next_line/public \
	-Ilibft/ft_printf/public -Isrcs/utils/include -Isrcs/shader \
	-Isrcs/shader_loader/include -Isrcs/shader_loader/include/public
$(O_DIR)/srcs/shader_loader/load_shader.o: srcs/shader_loader/load_shader.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_list/public/ft_list.h srcs/gl/gl.h srcs/shader/shader.h \
	srcs/shader_loader/include/internal.h \
	srcs/shader_loader/include/public/shader_loader.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/shader_loader/
$(O_DIR)/srcs/shader_loader/load_uniforms.o: INCLUDE_FLAGS += -Isrcs/gl \
	-Ilibft/ft_base/public -Ilibft/ft_hmap -Ilibft/ft_hmap/public \
	-Ilibft/ft_list/public -Ilibft/ft_out/public -Ilibft/get_next_line/public \
	-Ilibft/ft_printf/public -Isrcs/utils/include -Isrcs/shader \
	-Isrcs/shader_loader/include -Isrcs/shader_loader/include/public
$(O_DIR)/srcs/shader_loader/load_uniforms.o: \
	srcs/shader_loader/load_uniforms.c libft/ft_base/public/libft.h \
	libft/ft_hmap/public/ft_hmap.h srcs/gl/gl.h srcs/shader/shader.h \
	srcs/shader_loader/include/internal.h \
	srcs/shader_loader/include/public/shader_loader.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/shader_loader/
$(O_DIR)/srcs/shader_loader/read_shader.o: INCLUDE_FLAGS += -Isrcs/gl \
	-Ilibft/ft_base/public -Ilibft/ft_hmap -Ilibft/ft_hmap/public \
	-Ilibft/ft_list/public -Ilibft/ft_out/public -Ilibft/get_next_line/public \
	-Ilibft/ft_printf/public -Isrcs/utils/include -Isrcs/shader \
	-Isrcs/shader_loader/include -Isrcs/shader_loader/include/public
$(O_DIR)/srcs/shader_loader/read_shader.o: srcs/shader_loader/read_shader.c \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h \
	libft/get_next_line/public/get_next_line.h srcs/gl/gl.h \
	srcs/shader/shader.h srcs/shader_loader/include/internal.h \
	srcs/shader_loader/include/public/shader_loader.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/shader_loader/
$(O_DIR)/srcs/shader_loader/shader_get_uniform.o: INCLUDE_FLAGS += -Isrcs/gl \
	-Ilibft/ft_base/public -Ilibft/ft_hmap -Ilibft/ft_hmap/public \
	-Ilibft/ft_list/public -Ilibft/ft_out/public -Ilibft/get_next_line/public \
	-Ilibft/ft_printf/public -Isrcs/utils/include -Isrcs/shader \
	-Isrcs/shader_loader/include -Isrcs/shader_loader/include/public
$(O_DIR)/srcs/shader_loader/shader_get_uniform.o: \
	srcs/shader_loader/shader_get_uniform.c libft/ft_base/public/libft.h \
	libft/ft_hmap/public/ft_hmap.h srcs/shader/shader.h \
	srcs/shader_loader/include/internal.h \
	srcs/shader_loader/include/public/shader_loader.h \
	| $(O_DIR)/srcs/shader_loader/

# module transform
$(O_DIR)/srcs/transform/ft_transform_get.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include -Isrcs/transform/include
$(O_DIR)/srcs/transform/ft_transform_get.o: srcs/transform/ft_transform_get.c \
	srcs/math_utils/include/math_utils.h srcs/transform/include/transform.h \
	| $(O_DIR)/srcs/transform/
$(O_DIR)/srcs/transform/ft_transform_move.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include -Isrcs/transform/include
$(O_DIR)/srcs/transform/ft_transform_move.o: \
	srcs/transform/ft_transform_move.c srcs/math_utils/include/math_utils.h \
	srcs/transform/include/transform.h | $(O_DIR)/srcs/transform/
$(O_DIR)/srcs/transform/ft_transform_reflect.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include -Isrcs/transform/include
$(O_DIR)/srcs/transform/ft_transform_reflect.o: \
	srcs/transform/ft_transform_reflect.c srcs/math_utils/include/math_utils.h \
	srcs/transform/include/transform.h | $(O_DIR)/srcs/transform/
$(O_DIR)/srcs/transform/ft_transform_rotate.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include -Isrcs/transform/include
$(O_DIR)/srcs/transform/ft_transform_rotate.o: \
	srcs/transform/ft_transform_rotate.c srcs/math_utils/include/math_utils.h \
	srcs/transform/include/transform.h | $(O_DIR)/srcs/transform/
$(O_DIR)/srcs/transform/ft_transform_scale.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include -Isrcs/transform/include
$(O_DIR)/srcs/transform/ft_transform_scale.o: \
	srcs/transform/ft_transform_scale.c srcs/math_utils/include/math_utils.h \
	srcs/transform/include/transform.h | $(O_DIR)/srcs/transform/
$(O_DIR)/srcs/transform/ft_transform_shear.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include -Isrcs/transform/include
$(O_DIR)/srcs/transform/ft_transform_shear.o: \
	srcs/transform/ft_transform_shear.c srcs/math_utils/include/math_utils.h \
	srcs/transform/include/transform.h | $(O_DIR)/srcs/transform/

# module texture

# module camera
$(O_DIR)/srcs/camera/camera_get_view.o: INCLUDE_FLAGS += -Isrcs/camera/include \
	-Isrcs/math_utils/include
$(O_DIR)/srcs/camera/camera_get_view.o: srcs/camera/camera_get_view.c \
	srcs/camera/include/camera.h srcs/math_utils/include/math_utils.h \
	| $(O_DIR)/srcs/camera/
$(O_DIR)/srcs/camera/camera_look.o: INCLUDE_FLAGS += -Isrcs/camera/include \
	-Isrcs/math_utils/include
$(O_DIR)/srcs/camera/camera_look.o: srcs/camera/camera_look.c \
	srcs/camera/include/camera.h srcs/math_utils/include/math_utils.h \
	| $(O_DIR)/srcs/camera/
$(O_DIR)/srcs/camera/camera_move.o: INCLUDE_FLAGS += -Isrcs/camera/include \
	-Isrcs/math_utils/include
$(O_DIR)/srcs/camera/camera_move.o: srcs/camera/camera_move.c \
	srcs/camera/include/camera.h srcs/math_utils/include/math_utils.h \
	| $(O_DIR)/srcs/camera/

# module ft::vector
$(O_DIR)/libft/ft_vector/ft_vclear.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_vector/public
$(O_DIR)/libft/ft_vector/ft_vclear.o: libft/ft_vector/ft_vclear.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h \
	| $(O_DIR)/libft/ft_vector/
$(O_DIR)/libft/ft_vector/ft_vpush_back.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_vector/public
$(O_DIR)/libft/ft_vector/ft_vpush_back.o: libft/ft_vector/ft_vpush_back.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h \
	| $(O_DIR)/libft/ft_vector/
$(O_DIR)/libft/ft_vector/ft_vremove.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_vector/public
$(O_DIR)/libft/ft_vector/ft_vremove.o: libft/ft_vector/ft_vremove.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h \
	| $(O_DIR)/libft/ft_vector/
$(O_DIR)/libft/ft_vector/ft_vreserve.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_vector/public
$(O_DIR)/libft/ft_vector/ft_vreserve.o: libft/ft_vector/ft_vreserve.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h \
	| $(O_DIR)/libft/ft_vector/

# module main
$(O_DIR)/srcs/main/callbacks.o: MDR += lol
$(O_DIR)/srcs/main/callbacks.o: INCLUDE_FLAGS += -Isrcs/main/include -Isrcs/gl \
	-Ilibft/ft_base/public -Ilibft/ft_hmap -Ilibft/ft_hmap/public \
	-Ilibft/ft_list/public -Ilibft/ft_out/public -Ilibft/ft_vector/public \
	-Ilibft/get_next_line/public -Ilibft/ft_printf/public -Isrcs/anim/include \
	-Isrcs/camera/include -Isrcs/events/include -Isrcs/math_utils/include \
	-Isrcs/obj/include -Isrcs/obj_anim/include -Isrcs/renderer/include \
	-Isrcs/renderer/include/public -Isrcs/transform/include \
	-Isrcs/utils/include -Isrcs/shader -Isrcs/shader_loader/include/public \
	-Isrcs/mesh -Isrcs/mesh_loader/include -Isrcs/mesh_loader/include/public \
	-Isrcs/mtl -Isrcs/mtl_loader/include/public -Isrcs/texture
$(O_DIR)/srcs/main/callbacks.o: srcs/main/callbacks.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h \
	srcs/anim/include/anim.h srcs/camera/include/camera.h \
	srcs/events/include/events.h srcs/gl/gl.h srcs/main/include/main.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/renderer/include/public/renderer.h \
	srcs/texture/texture.h srcs/transform/include/transform.h \
	| $(O_DIR)/srcs/main/
$(O_DIR)/srcs/main/init_window.o: MDR += lol
$(O_DIR)/srcs/main/init_window.o: INCLUDE_FLAGS += -Isrcs/main/include \
	-Isrcs/gl -Ilibft/ft_base/public -Ilibft/ft_hmap -Ilibft/ft_hmap/public \
	-Ilibft/ft_list/public -Ilibft/ft_out/public -Ilibft/ft_vector/public \
	-Ilibft/get_next_line/public -Ilibft/ft_printf/public -Isrcs/anim/include \
	-Isrcs/camera/include -Isrcs/events/include -Isrcs/math_utils/include \
	-Isrcs/obj/include -Isrcs/obj_anim/include -Isrcs/renderer/include \
	-Isrcs/renderer/include/public -Isrcs/transform/include \
	-Isrcs/utils/include -Isrcs/shader -Isrcs/shader_loader/include/public \
	-Isrcs/mesh -Isrcs/mesh_loader/include -Isrcs/mesh_loader/include/public \
	-Isrcs/mtl -Isrcs/mtl_loader/include/public -Isrcs/texture
$(O_DIR)/srcs/main/init_window.o: srcs/main/init_window.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h \
	srcs/anim/include/anim.h srcs/camera/include/camera.h srcs/gl/gl.h \
	srcs/main/include/main.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mtl/mtl.h srcs/obj/include/obj.h \
	srcs/renderer/include/public/renderer.h srcs/texture/texture.h \
	srcs/transform/include/transform.h srcs/utils/include/utils.h \
	| $(O_DIR)/srcs/main/
$(O_DIR)/srcs/main/main.o: MDR += lol
$(O_DIR)/srcs/main/main.o: INCLUDE_FLAGS += -Isrcs/main/include -Isrcs/gl \
	-Ilibft/ft_base/public -Ilibft/ft_hmap -Ilibft/ft_hmap/public \
	-Ilibft/ft_list/public -Ilibft/ft_out/public -Ilibft/ft_vector/public \
	-Ilibft/get_next_line/public -Ilibft/ft_printf/public -Isrcs/anim/include \
	-Isrcs/camera/include -Isrcs/events/include -Isrcs/math_utils/include \
	-Isrcs/obj/include -Isrcs/obj_anim/include -Isrcs/renderer/include \
	-Isrcs/renderer/include/public -Isrcs/transform/include \
	-Isrcs/utils/include -Isrcs/shader -Isrcs/shader_loader/include/public \
	-Isrcs/mesh -Isrcs/mesh_loader/include -Isrcs/mesh_loader/include/public \
	-Isrcs/mtl -Isrcs/mtl_loader/include/public -Isrcs/texture
$(O_DIR)/srcs/main/main.o: srcs/main/main.c libft/ft_base/public/libft.h \
	libft/ft_printf/public/ft_printf.h libft/ft_vector/public/ft_vector.h \
	srcs/anim/include/anim.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/events/include/events.h srcs/gl/gl.h \
	srcs/main/include/main.h srcs/math_utils/include/math_utils.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h srcs/mesh/mesh.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/obj/include/obj.h \
	srcs/obj_anim/include/obj_anim.h srcs/renderer/include/public/renderer.h \
	srcs/renderer/include/public/renderer.h srcs/shader/shader.h \
	srcs/texture/texture.h srcs/transform/include/transform.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/main/
$(O_DIR)/srcs/main/motions.o: MDR += lol
$(O_DIR)/srcs/main/motions.o: INCLUDE_FLAGS += -Isrcs/main/include -Isrcs/gl \
	-Ilibft/ft_base/public -Ilibft/ft_hmap -Ilibft/ft_hmap/public \
	-Ilibft/ft_list/public -Ilibft/ft_out/public -Ilibft/ft_vector/public \
	-Ilibft/get_next_line/public -Ilibft/ft_printf/public -Isrcs/anim/include \
	-Isrcs/camera/include -Isrcs/events/include -Isrcs/math_utils/include \
	-Isrcs/obj/include -Isrcs/obj_anim/include -Isrcs/renderer/include \
	-Isrcs/renderer/include/public -Isrcs/transform/include \
	-Isrcs/utils/include -Isrcs/shader -Isrcs/shader_loader/include/public \
	-Isrcs/mesh -Isrcs/mesh_loader/include -Isrcs/mesh_loader/include/public \
	-Isrcs/mtl -Isrcs/mtl_loader/include/public -Isrcs/texture
$(O_DIR)/srcs/main/motions.o: srcs/main/motions.c libft/ft_base/public/libft.h \
	libft/ft_vector/public/ft_vector.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/gl/gl.h srcs/main/include/main.h \
	srcs/main/include/motions.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mtl/mtl.h srcs/obj/include/obj.h \
	srcs/renderer/include/public/renderer.h srcs/texture/texture.h \
	srcs/transform/include/transform.h | $(O_DIR)/srcs/main/

# module ft::get_next_line
$(O_DIR)/libft/get_next_line/get_next_line.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/get_next_line -Ilibft/get_next_line/public
$(O_DIR)/libft/get_next_line/get_next_line.o: \
	libft/get_next_line/get_next_line.c libft/ft_base/public/libft.h \
	libft/get_next_line/gnl_internal.h \
	libft/get_next_line/public/get_next_line.h | $(O_DIR)/libft/get_next_line/

# module obj_anim
$(O_DIR)/srcs/obj_anim/anim_c_move.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Isrcs/anim/include -Isrcs/camera/include -Isrcs/math_utils/include \
	-Isrcs/obj/include -Isrcs/obj_anim/include -Isrcs/transform/include \
	-Isrcs/mesh -Isrcs/mtl -Isrcs/texture
$(O_DIR)/srcs/obj_anim/anim_c_move.o: srcs/obj_anim/anim_c_move.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mtl/mtl.h srcs/obj/include/obj.h \
	srcs/obj/include/obj.h srcs/obj_anim/include/obj_anim.h \
	srcs/texture/texture.h srcs/transform/include/transform.h \
	| $(O_DIR)/srcs/obj_anim/
$(O_DIR)/srcs/obj_anim/anim_c_rot.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Isrcs/anim/include -Isrcs/camera/include -Isrcs/math_utils/include \
	-Isrcs/obj/include -Isrcs/obj_anim/include -Isrcs/transform/include \
	-Isrcs/mesh -Isrcs/mtl -Isrcs/texture
$(O_DIR)/srcs/obj_anim/anim_c_rot.o: srcs/obj_anim/anim_c_rot.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mtl/mtl.h srcs/obj/include/obj.h \
	srcs/obj/include/obj.h srcs/obj_anim/include/obj_anim.h \
	srcs/texture/texture.h srcs/transform/include/transform.h \
	| $(O_DIR)/srcs/obj_anim/
$(O_DIR)/srcs/obj_anim/anim_c_scale.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Isrcs/anim/include -Isrcs/camera/include -Isrcs/math_utils/include \
	-Isrcs/obj/include -Isrcs/obj_anim/include -Isrcs/transform/include \
	-Isrcs/mesh -Isrcs/mtl -Isrcs/texture
$(O_DIR)/srcs/obj_anim/anim_c_scale.o: srcs/obj_anim/anim_c_scale.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mtl/mtl.h srcs/obj/include/obj.h \
	srcs/obj/include/obj.h srcs/obj_anim/include/obj_anim.h \
	srcs/texture/texture.h srcs/transform/include/transform.h \
	| $(O_DIR)/srcs/obj_anim/
$(O_DIR)/srcs/obj_anim/anim_c_shear.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Isrcs/anim/include -Isrcs/camera/include -Isrcs/math_utils/include \
	-Isrcs/obj/include -Isrcs/obj_anim/include -Isrcs/transform/include \
	-Isrcs/mesh -Isrcs/mtl -Isrcs/texture
$(O_DIR)/srcs/obj_anim/anim_c_shear.o: srcs/obj_anim/anim_c_shear.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mtl/mtl.h srcs/obj/include/obj.h \
	srcs/obj/include/obj.h srcs/obj_anim/include/obj_anim.h \
	srcs/texture/texture.h srcs/transform/include/transform.h \
	| $(O_DIR)/srcs/obj_anim/

# module anim
$(O_DIR)/srcs/anim/anim_start.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Isrcs/anim/include
$(O_DIR)/srcs/anim/anim_start.o: srcs/anim/anim_start.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	| $(O_DIR)/srcs/anim/
$(O_DIR)/srcs/anim/anim_update.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Isrcs/anim/include
$(O_DIR)/srcs/anim/anim_update.o: srcs/anim/anim_update.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	| $(O_DIR)/srcs/anim/
$(O_DIR)/srcs/anim/smooth_back_in.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Isrcs/anim/include
$(O_DIR)/srcs/anim/smooth_back_in.o: srcs/anim/smooth_back_in.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	| $(O_DIR)/srcs/anim/
$(O_DIR)/srcs/anim/smooth_back_in_out.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Isrcs/anim/include
$(O_DIR)/srcs/anim/smooth_back_in_out.o: srcs/anim/smooth_back_in_out.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	| $(O_DIR)/srcs/anim/
$(O_DIR)/srcs/anim/smooth_back_out.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Isrcs/anim/include
$(O_DIR)/srcs/anim/smooth_back_out.o: srcs/anim/smooth_back_out.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	| $(O_DIR)/srcs/anim/
$(O_DIR)/srcs/anim/smooth_bounce.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Isrcs/anim/include
$(O_DIR)/srcs/anim/smooth_bounce.o: srcs/anim/smooth_bounce.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	| $(O_DIR)/srcs/anim/
$(O_DIR)/srcs/anim/smooth_elastic.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Isrcs/anim/include
$(O_DIR)/srcs/anim/smooth_elastic.o: srcs/anim/smooth_elastic.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	| $(O_DIR)/srcs/anim/
$(O_DIR)/srcs/anim/smooth_in.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Isrcs/anim/include
$(O_DIR)/srcs/anim/smooth_in.o: srcs/anim/smooth_in.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	| $(O_DIR)/srcs/anim/
$(O_DIR)/srcs/anim/smooth_in_out.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Isrcs/anim/include
$(O_DIR)/srcs/anim/smooth_in_out.o: srcs/anim/smooth_in_out.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	| $(O_DIR)/srcs/anim/
$(O_DIR)/srcs/anim/smooth_linear.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Isrcs/anim/include
$(O_DIR)/srcs/anim/smooth_linear.o: srcs/anim/smooth_linear.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	| $(O_DIR)/srcs/anim/
$(O_DIR)/srcs/anim/smooth_out.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Isrcs/anim/include
$(O_DIR)/srcs/anim/smooth_out.o: srcs/anim/smooth_out.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	| $(O_DIR)/srcs/anim/

# module mesh

# module ft::out
$(O_DIR)/libft/ft_out/ft_flush.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_dstr/public -Ilibft/ft_out/public
$(O_DIR)/libft/ft_out/ft_flush.o: libft/ft_out/ft_flush.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	| $(O_DIR)/libft/ft_out/
$(O_DIR)/libft/ft_out/ft_hexdump.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_dstr/public -Ilibft/ft_out/public
$(O_DIR)/libft/ft_out/ft_hexdump.o: libft/ft_out/ft_hexdump.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	| $(O_DIR)/libft/ft_out/
$(O_DIR)/libft/ft_out/ft_out.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_dstr/public -Ilibft/ft_out/public
$(O_DIR)/libft/ft_out/ft_out.o: libft/ft_out/ft_out.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	| $(O_DIR)/libft/ft_out/
$(O_DIR)/libft/ft_out/ft_write.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_dstr/public -Ilibft/ft_out/public
$(O_DIR)/libft/ft_out/ft_write.o: libft/ft_out/ft_write.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h | $(O_DIR)/libft/ft_out/
$(O_DIR)/libft/ft_out/ft_writebase.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_dstr/public -Ilibft/ft_out/public
$(O_DIR)/libft/ft_out/ft_writebase.o: libft/ft_out/ft_writebase.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	| $(O_DIR)/libft/ft_out/
$(O_DIR)/libft/ft_out/ft_writechar.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_dstr/public -Ilibft/ft_out/public
$(O_DIR)/libft/ft_out/ft_writechar.o: libft/ft_out/ft_writechar.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h | $(O_DIR)/libft/ft_out/
$(O_DIR)/libft/ft_out/ft_writedouble.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public
$(O_DIR)/libft/ft_out/ft_writedouble.o: libft/ft_out/ft_writedouble.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	| $(O_DIR)/libft/ft_out/
$(O_DIR)/libft/ft_out/ft_writeint.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_dstr/public -Ilibft/ft_out/public
$(O_DIR)/libft/ft_out/ft_writeint.o: libft/ft_out/ft_writeint.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	| $(O_DIR)/libft/ft_out/
$(O_DIR)/libft/ft_out/ft_writenchar.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_dstr/public -Ilibft/ft_out/public
$(O_DIR)/libft/ft_out/ft_writenchar.o: libft/ft_out/ft_writenchar.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h | $(O_DIR)/libft/ft_out/
$(O_DIR)/libft/ft_out/ft_writenl.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_dstr/public -Ilibft/ft_out/public
$(O_DIR)/libft/ft_out/ft_writenl.o: libft/ft_out/ft_writenl.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	| $(O_DIR)/libft/ft_out/
$(O_DIR)/libft/ft_out/ft_writestr.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_dstr/public -Ilibft/ft_out/public
$(O_DIR)/libft/ft_out/ft_writestr.o: libft/ft_out/ft_writestr.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	| $(O_DIR)/libft/ft_out/

# module ft::dstr
$(O_DIR)/libft/ft_dstr/ft_dstradd.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_dstr/public
$(O_DIR)/libft/ft_dstr/ft_dstradd.o: libft/ft_dstr/ft_dstradd.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	| $(O_DIR)/libft/ft_dstr/
$(O_DIR)/libft/ft_dstr/ft_dstrclear.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_dstr/public
$(O_DIR)/libft/ft_dstr/ft_dstrclear.o: libft/ft_dstr/ft_dstrclear.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	| $(O_DIR)/libft/ft_dstr/
$(O_DIR)/libft/ft_dstr/ft_dstrextend.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public
$(O_DIR)/libft/ft_dstr/ft_dstrextend.o: libft/ft_dstr/ft_dstrextend.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	| $(O_DIR)/libft/ft_dstr/
$(O_DIR)/libft/ft_dstr/ft_dstrspan.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_dstr/public
$(O_DIR)/libft/ft_dstr/ft_dstrspan.o: libft/ft_dstr/ft_dstrspan.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	| $(O_DIR)/libft/ft_dstr/

# module ft::list
$(O_DIR)/libft/ft_list/ft_listadd.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_list/public
$(O_DIR)/libft/ft_list/ft_listadd.o: libft/ft_list/ft_listadd.c \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h \
	| $(O_DIR)/libft/ft_list/
$(O_DIR)/libft/ft_list/ft_listremove.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_list/public
$(O_DIR)/libft/ft_list/ft_listremove.o: libft/ft_list/ft_listremove.c \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h \
	| $(O_DIR)/libft/ft_list/
$(O_DIR)/libft/ft_list/ft_listsort.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_list/public
$(O_DIR)/libft/ft_list/ft_listsort.o: libft/ft_list/ft_listsort.c \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h \
	| $(O_DIR)/libft/ft_list/

# module obj

# module shader

# module math_utils
$(O_DIR)/srcs/math_utils/ft_mat4look_at.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include
$(O_DIR)/srcs/math_utils/ft_mat4look_at.o: srcs/math_utils/ft_mat4look_at.c \
	srcs/math_utils/include/math_utils.h | $(O_DIR)/srcs/math_utils/
$(O_DIR)/srcs/math_utils/ft_mat4mult.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include
$(O_DIR)/srcs/math_utils/ft_mat4mult.o: srcs/math_utils/ft_mat4mult.c \
	srcs/math_utils/include/math_utils.h | $(O_DIR)/srcs/math_utils/
$(O_DIR)/srcs/math_utils/ft_mat4perspective.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include
$(O_DIR)/srcs/math_utils/ft_mat4perspective.o: \
	srcs/math_utils/ft_mat4perspective.c srcs/math_utils/include/math_utils.h \
	| $(O_DIR)/srcs/math_utils/
$(O_DIR)/srcs/math_utils/ft_mat4reflect.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include
$(O_DIR)/srcs/math_utils/ft_mat4reflect.o: srcs/math_utils/ft_mat4reflect.c \
	srcs/math_utils/include/math_utils.h | $(O_DIR)/srcs/math_utils/
$(O_DIR)/srcs/math_utils/ft_mat4rotate.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include
$(O_DIR)/srcs/math_utils/ft_mat4rotate.o: srcs/math_utils/ft_mat4rotate.c \
	srcs/math_utils/include/math_utils.h | $(O_DIR)/srcs/math_utils/
$(O_DIR)/srcs/math_utils/ft_mat4scale.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include
$(O_DIR)/srcs/math_utils/ft_mat4scale.o: srcs/math_utils/ft_mat4scale.c \
	srcs/math_utils/include/math_utils.h | $(O_DIR)/srcs/math_utils/
$(O_DIR)/srcs/math_utils/ft_mat4shear.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include
$(O_DIR)/srcs/math_utils/ft_mat4shear.o: srcs/math_utils/ft_mat4shear.c \
	srcs/math_utils/include/math_utils.h | $(O_DIR)/srcs/math_utils/
$(O_DIR)/srcs/math_utils/ft_mat4translate.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include
$(O_DIR)/srcs/math_utils/ft_mat4translate.o: \
	srcs/math_utils/ft_mat4translate.c srcs/math_utils/include/math_utils.h \
	| $(O_DIR)/srcs/math_utils/
$(O_DIR)/srcs/math_utils/ft_mat4transpose.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include
$(O_DIR)/srcs/math_utils/ft_mat4transpose.o: \
	srcs/math_utils/ft_mat4transpose.c srcs/math_utils/include/math_utils.h \
	| $(O_DIR)/srcs/math_utils/
$(O_DIR)/srcs/math_utils/ft_vec3cross.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include
$(O_DIR)/srcs/math_utils/ft_vec3cross.o: srcs/math_utils/ft_vec3cross.c \
	srcs/math_utils/include/math_utils.h | $(O_DIR)/srcs/math_utils/
$(O_DIR)/srcs/math_utils/ft_vec3dot.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include
$(O_DIR)/srcs/math_utils/ft_vec3dot.o: srcs/math_utils/ft_vec3dot.c \
	srcs/math_utils/include/math_utils.h | $(O_DIR)/srcs/math_utils/
$(O_DIR)/srcs/math_utils/ft_vec3front.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include
$(O_DIR)/srcs/math_utils/ft_vec3front.o: srcs/math_utils/ft_vec3front.c \
	srcs/math_utils/include/math_utils.h | $(O_DIR)/srcs/math_utils/
$(O_DIR)/srcs/math_utils/ft_vec3norm.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include
$(O_DIR)/srcs/math_utils/ft_vec3norm.o: srcs/math_utils/ft_vec3norm.c \
	srcs/math_utils/include/math_utils.h | $(O_DIR)/srcs/math_utils/
$(O_DIR)/srcs/math_utils/ft_vec3rotate.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include
$(O_DIR)/srcs/math_utils/ft_vec3rotate.o: srcs/math_utils/ft_vec3rotate.c \
	srcs/math_utils/include/math_utils.h | $(O_DIR)/srcs/math_utils/
$(O_DIR)/srcs/math_utils/ft_vec3sub.o: INCLUDE_FLAGS += \
	-Isrcs/math_utils/include
$(O_DIR)/srcs/math_utils/ft_vec3sub.o: srcs/math_utils/ft_vec3sub.c \
	srcs/math_utils/include/math_utils.h | $(O_DIR)/srcs/math_utils/

# module ft::printf
$(O_DIR)/libft/ft_printf/args_utils.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_dstr/public -Ilibft/ft_out/public -Ilibft/ft_printf \
	-Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/args_utils.o: libft/ft_printf/args_utils.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/
$(O_DIR)/libft/ft_printf/flags/flag_b.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/flags/flag_b.o: libft/ft_printf/flags/flag_b.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/flags/
$(O_DIR)/libft/ft_printf/flags/flag_c.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/flags/flag_c.o: libft/ft_printf/flags/flag_c.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	| $(O_DIR)/libft/ft_printf/flags/
$(O_DIR)/libft/ft_printf/flags/flag_d.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/flags/flag_d.o: libft/ft_printf/flags/flag_d.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/flags/
$(O_DIR)/libft/ft_printf/flags/flag_f.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/flags/flag_f.o: libft/ft_printf/flags/flag_f.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/flags/
$(O_DIR)/libft/ft_printf/flags/flag_n.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/flags/flag_n.o: libft/ft_printf/flags/flag_n.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/flags/
$(O_DIR)/libft/ft_printf/flags/flag_o.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/flags/flag_o.o: libft/ft_printf/flags/flag_o.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/flags/
$(O_DIR)/libft/ft_printf/flags/flag_other.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/flags/flag_other.o: \
	libft/ft_printf/flags/flag_other.c libft/ft_base/public/libft.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	| $(O_DIR)/libft/ft_printf/flags/
$(O_DIR)/libft/ft_printf/flags/flag_p.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/flags/flag_p.o: libft/ft_printf/flags/flag_p.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/flags/
$(O_DIR)/libft/ft_printf/flags/flag_percent.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/flags/flag_percent.o: \
	libft/ft_printf/flags/flag_percent.c libft/ft_base/public/libft.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	| $(O_DIR)/libft/ft_printf/flags/
$(O_DIR)/libft/ft_printf/flags/flag_r.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/flags/flag_r.o: libft/ft_printf/flags/flag_r.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/flags/
$(O_DIR)/libft/ft_printf/flags/flag_rr.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/flags/flag_rr.o: libft/ft_printf/flags/flag_rr.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/flags/
$(O_DIR)/libft/ft_printf/flags/flag_s.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/flags/flag_s.o: libft/ft_printf/flags/flag_s.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	| $(O_DIR)/libft/ft_printf/flags/
$(O_DIR)/libft/ft_printf/flags/flag_u.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/flags/flag_u.o: libft/ft_printf/flags/flag_u.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/flags/
$(O_DIR)/libft/ft_printf/flags/flag_w.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/flags/flag_w.o: libft/ft_printf/flags/flag_w.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/flags/
$(O_DIR)/libft/ft_printf/flags/flag_x.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/flags/flag_x.o: libft/ft_printf/flags/flag_x.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/flags/
$(O_DIR)/libft/ft_printf/flags_utils.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/flags_utils.o: libft/ft_printf/flags_utils.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/
$(O_DIR)/libft/ft_printf/ft_aprintf.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_dstr/public -Ilibft/ft_out/public -Ilibft/ft_printf \
	-Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/ft_aprintf.o: libft/ft_printf/ft_aprintf.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	| $(O_DIR)/libft/ft_printf/
$(O_DIR)/libft/ft_printf/ft_asprintf.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/ft_asprintf.o: libft/ft_printf/ft_asprintf.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	| $(O_DIR)/libft/ft_printf/
$(O_DIR)/libft/ft_printf/ft_fdprintf.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/ft_fdprintf.o: libft/ft_printf/ft_fdprintf.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/
$(O_DIR)/libft/ft_printf/ft_printf.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_dstr/public -Ilibft/ft_out/public -Ilibft/ft_printf \
	-Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/ft_printf.o: libft/ft_printf/ft_printf.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/
$(O_DIR)/libft/ft_printf/ft_snprintf.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/ft_snprintf.o: libft/ft_printf/ft_snprintf.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/
$(O_DIR)/libft/ft_printf/ft_sprintf.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_dstr/public -Ilibft/ft_out/public -Ilibft/ft_printf \
	-Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/ft_sprintf.o: libft/ft_printf/ft_sprintf.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/
$(O_DIR)/libft/ft_printf/ft_writef.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_dstr/public -Ilibft/ft_out/public -Ilibft/ft_printf \
	-Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/ft_writef.o: libft/ft_printf/ft_writef.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/
$(O_DIR)/libft/ft_printf/metas/meta_fl.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/metas/meta_fl.o: libft/ft_printf/metas/meta_fl.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/metas/
$(O_DIR)/libft/ft_printf/metas/meta_nl.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/metas/meta_nl.o: libft/ft_printf/metas/meta_nl.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/metas/
$(O_DIR)/libft/ft_printf/metas_utils.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/metas_utils.o: libft/ft_printf/metas_utils.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/
$(O_DIR)/libft/ft_printf/parse_format.o: INCLUDE_FLAGS += \
	-Ilibft/ft_base/public -Ilibft/ft_dstr/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf -Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/parse_format.o: libft/ft_printf/parse_format.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/
$(O_DIR)/libft/ft_printf/parse_meta.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_dstr/public -Ilibft/ft_out/public -Ilibft/ft_printf \
	-Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/parse_meta.o: libft/ft_printf/parse_meta.c \
	libft/ft_base/public/ft_colors.h libft/ft_base/public/libft.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	| $(O_DIR)/libft/ft_printf/
$(O_DIR)/libft/ft_printf/writef.o: INCLUDE_FLAGS += -Ilibft/ft_base/public \
	-Ilibft/ft_dstr/public -Ilibft/ft_out/public -Ilibft/ft_printf \
	-Ilibft/ft_printf/public
$(O_DIR)/libft/ft_printf/writef.o: libft/ft_printf/writef.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h | $(O_DIR)/libft/ft_printf/

# module texture_loader
$(O_DIR)/srcs/texture_loader/ft_loadimage.o: INCLUDE_FLAGS += \
	-Isrcs/texture_loader/include -Isrcs/texture_loader/include/public \
	-Isrcs/gl -Ilibft/ft_base/public -Ilibft/ft_buff/public -Ilibft/ft_hmap \
	-Ilibft/ft_hmap/public -Ilibft/ft_list/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf/public -Isrcs/utils/include -Isrcs/texture
$(O_DIR)/srcs/texture_loader/ft_loadimage.o: \
	srcs/texture_loader/ft_loadimage.c libft/ft_base/public/libft.h \
	libft/ft_buff/public/ft_buff.h libft/ft_buff/public/ft_buff.h \
	srcs/texture_loader/include/ft_img.h | $(O_DIR)/srcs/texture_loader/
$(O_DIR)/srcs/texture_loader/load_texture.o: INCLUDE_FLAGS += \
	-Isrcs/texture_loader/include -Isrcs/texture_loader/include/public \
	-Isrcs/gl -Ilibft/ft_base/public -Ilibft/ft_buff/public -Ilibft/ft_hmap \
	-Ilibft/ft_hmap/public -Ilibft/ft_list/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf/public -Isrcs/utils/include -Isrcs/texture
$(O_DIR)/srcs/texture_loader/load_texture.o: \
	srcs/texture_loader/load_texture.c libft/ft_base/public/libft.h \
	libft/ft_buff/public/ft_buff.h libft/ft_hmap/public/ft_hmap.h srcs/gl/gl.h \
	srcs/texture/texture.h srcs/texture_loader/include/ft_img.h \
	srcs/texture_loader/include/internal.h \
	srcs/texture_loader/include/public/texture_loader.h \
	| $(O_DIR)/srcs/texture_loader/
$(O_DIR)/srcs/texture_loader/tga_parser.o: INCLUDE_FLAGS += \
	-Isrcs/texture_loader/include -Isrcs/texture_loader/include/public \
	-Isrcs/gl -Ilibft/ft_base/public -Ilibft/ft_buff/public -Ilibft/ft_hmap \
	-Ilibft/ft_hmap/public -Ilibft/ft_list/public -Ilibft/ft_out/public \
	-Ilibft/ft_printf/public -Isrcs/utils/include -Isrcs/texture
$(O_DIR)/srcs/texture_loader/tga_parser.o: srcs/texture_loader/tga_parser.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h \
	libft/ft_buff/public/ft_buff.h srcs/texture_loader/include/ft_img.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/texture_loader/

# module mtl
