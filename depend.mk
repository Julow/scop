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
	$(O_DIR)/libft/ft_base/ft_assert.o $(O_DIR)/libft/ft_base/ft_atoib.o \
	$(O_DIR)/libft/ft_base/ft_bzero.o $(O_DIR)/libft/ft_base/ft_clock.o \
	$(O_DIR)/libft/ft_base/ft_emalloc.o $(O_DIR)/libft/ft_base/ft_escape.o \
	$(O_DIR)/libft/ft_base/ft_is.o $(O_DIR)/libft/ft_base/ft_max.o \
	$(O_DIR)/libft/ft_base/ft_memcmp.o $(O_DIR)/libft/ft_base/ft_memcpy.o \
	$(O_DIR)/libft/ft_base/ft_memdup.o $(O_DIR)/libft/ft_base/ft_memfill.o \
	$(O_DIR)/libft/ft_base/ft_memmove.o $(O_DIR)/libft/ft_base/ft_memrcpy.o \
	$(O_DIR)/libft/ft_base/ft_memset.o $(O_DIR)/libft/ft_base/ft_memstart.o \
	$(O_DIR)/libft/ft_base/ft_memswap.o $(O_DIR)/libft/ft_base/ft_min.o \
	$(O_DIR)/libft/ft_base/ft_nanoclock.o $(O_DIR)/libft/ft_base/ft_rand.o \
	$(O_DIR)/libft/ft_base/ft_randbool.o $(O_DIR)/libft/ft_base/ft_strchri.o \
	$(O_DIR)/libft/ft_base/ft_strlen.o $(O_DIR)/libft/ft_base/ft_sub.o \
	$(O_DIR)/libft/ft_base/ft_unescape.o $(O_DIR)/libft/ft_base/ft_widetoa.o \
	$(O_DIR)/libft/ft_base/ft_wstrconv.o $(O_DIR)/libft/ft_base/ft_wstrlen.o \
	$(O_DIR)/libft/ft_base/ft_wstrnconv.o \
	$(O_DIR)/libft/ft_buff/ft_buffclear.o $(O_DIR)/libft/ft_buff/ft_buffget.o \
	$(O_DIR)/libft/ft_buff/ft_parse.o $(O_DIR)/libft/ft_buff/ft_parsebase.o \
	$(O_DIR)/libft/ft_buff/ft_parsedouble.o \
	$(O_DIR)/libft/ft_buff/ft_parseendl.o $(O_DIR)/libft/ft_buff/ft_parsef.o \
	$(O_DIR)/libft/ft_buff/ft_parseint.o $(O_DIR)/libft/ft_buff/ft_parselong.o \
	$(O_DIR)/libft/ft_buff/ft_parsen.o $(O_DIR)/libft/ft_buff/ft_parsenot.o \
	$(O_DIR)/libft/ft_buff/ft_parsespace.o \
	$(O_DIR)/libft/ft_buff/ft_parsestr.o \
	$(O_DIR)/libft/ft_buff/ft_parsewhite.o \
	$(O_DIR)/libft/ft_buff/ft_readbuff.o \
	$(O_DIR)/libft/ft_count_out/ft_count_out.o \
	$(O_DIR)/libft/get_next_line/get_next_line.o \
	$(O_DIR)/libft/ft_hmap/ft_djb2.o $(O_DIR)/libft/ft_hmap/ft_hmapdatas.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapdestroy.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapget.o $(O_DIR)/libft/ft_hmap/ft_hmapkeys.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapnew.o $(O_DIR)/libft/ft_hmap/ft_hmapput.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapputp.o $(O_DIR)/libft/ft_hmap/ft_hmaprem.o \
	$(O_DIR)/libft/ft_hmap/hmap_puth.o $(O_DIR)/libft/ft_list/ft_listadd.o \
	$(O_DIR)/libft/ft_list/ft_listremove.o \
	$(O_DIR)/libft/ft_list/ft_listsort.o $(O_DIR)/libft/ft_out/ft_putchar.o \
	$(O_DIR)/libft/ft_out/ft_putendl.o $(O_DIR)/libft/ft_out/ft_putfloat.o \
	$(O_DIR)/libft/ft_out/ft_putint.o $(O_DIR)/libft/ft_out/ft_putnchar.o \
	$(O_DIR)/libft/ft_out/ft_putpad.o $(O_DIR)/libft/ft_out/ft_putstr.o \
	$(O_DIR)/libft/ft_out/ft_putsub.o $(O_DIR)/libft/ft_out/ft_putuint.o \
	$(O_DIR)/libft/ft_out/ft_write.o $(O_DIR)/libft/ft_out/ft_write_char.o \
	$(O_DIR)/libft/ft_out/ft_write_nchar.o $(O_DIR)/libft/ft_out/out_formats.o \
	$(O_DIR)/libft/ft_printf/args_utils.o \
	$(O_DIR)/libft/ft_printf/exec_format.o \
	$(O_DIR)/libft/ft_printf/exec_subformat.o \
	$(O_DIR)/libft/ft_printf/formats/char.o \
	$(O_DIR)/libft/ft_printf/formats/int.o \
	$(O_DIR)/libft/ft_printf/formats/misc.o \
	$(O_DIR)/libft/ft_printf/formats/str.o $(O_DIR)/libft/ft_printf/ft_out.o \
	$(O_DIR)/libft/ft_printf/ft_printf.o $(O_DIR)/libft/ft_printf/ft_putf.o \
	$(O_DIR)/libft/ft_printf/ft_vprintf.o $(O_DIR)/libft/ft_sub/ft_subchr.o \
	$(O_DIR)/libft/ft_sub/ft_subcount.o $(O_DIR)/libft/ft_sub/ft_subequ.o \
	$(O_DIR)/libft/ft_sub/ft_subextract.o $(O_DIR)/libft/ft_sub/ft_subfloat.o \
	$(O_DIR)/libft/ft_sub/ft_subindex.o $(O_DIR)/libft/ft_sub/ft_subint.o \
	$(O_DIR)/libft/ft_sub/ft_subnext.o $(O_DIR)/libft/ft_sub/ft_subnextc.o \
	$(O_DIR)/libft/ft_sub/ft_subsub.o $(O_DIR)/libft/ft_sub/ft_subtrim.o \
	$(O_DIR)/libft/ft_sub/ft_subtriml.o $(O_DIR)/libft/ft_sub/ft_subtrimr.o \
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
INCLUDE_FLAGS += -I$(O_DIR)/_public
PUBLIC_LINKS += $(O_DIR)/_public/anim.h $(O_DIR)/_public/camera.h \
	$(O_DIR)/_public/events.h $(O_DIR)/_public/ft/ft_buff.h \
	$(O_DIR)/_public/ft/ft_colors.h $(O_DIR)/_public/ft/ft_count_out.h \
	$(O_DIR)/_public/ft/ft_hmap.h $(O_DIR)/_public/ft/ft_list.h \
	$(O_DIR)/_public/ft/ft_out.h $(O_DIR)/_public/ft/ft_printf.h \
	$(O_DIR)/_public/ft/ft_sub.h $(O_DIR)/_public/ft/ft_vector.h \
	$(O_DIR)/_public/ft/ft_vprintf.h $(O_DIR)/_public/ft/ft_wchar.h \
	$(O_DIR)/_public/ft/get_next_line.h $(O_DIR)/_public/ft/libft.h \
	$(O_DIR)/_public/gl.h $(O_DIR)/_public/math_utils.h \
	$(O_DIR)/_public/mesh.h $(O_DIR)/_public/mesh_loader.h \
	$(O_DIR)/_public/mtl.h $(O_DIR)/_public/mtl_loader.h \
	$(O_DIR)/_public/obj.h $(O_DIR)/_public/obj_anim.h \
	$(O_DIR)/_public/renderer.h $(O_DIR)/_public/shader.h \
	$(O_DIR)/_public/shader_loader.h $(O_DIR)/_public/texture.h \
	$(O_DIR)/_public/texture_loader.h $(O_DIR)/_public/transform.h \
	$(O_DIR)/_public/utils.h
PUBLIC_LINK_DIRS += $(O_DIR)/_public/ $(O_DIR)/_public/ft/

$(PUBLIC_LINKS): | $(PUBLIC_LINK_DIRS)

# module anim
$(O_DIR)/srcs/anim/anim_start.o: srcs/anim/anim_start.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h
$(O_DIR)/srcs/anim/anim_update.o: srcs/anim/anim_update.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h
$(O_DIR)/srcs/anim/smooth_back_in.o: srcs/anim/smooth_back_in.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h
$(O_DIR)/srcs/anim/smooth_back_in_out.o: srcs/anim/smooth_back_in_out.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h
$(O_DIR)/srcs/anim/smooth_back_out.o: srcs/anim/smooth_back_out.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h
$(O_DIR)/srcs/anim/smooth_bounce.o: srcs/anim/smooth_bounce.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h
$(O_DIR)/srcs/anim/smooth_elastic.o: srcs/anim/smooth_elastic.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h
$(O_DIR)/srcs/anim/smooth_in.o: srcs/anim/smooth_in.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h
$(O_DIR)/srcs/anim/smooth_in_out.o: srcs/anim/smooth_in_out.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h
$(O_DIR)/srcs/anim/smooth_linear.o: srcs/anim/smooth_linear.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h
$(O_DIR)/srcs/anim/smooth_out.o: srcs/anim/smooth_out.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h

# module camera
$(O_DIR)/srcs/camera/camera_get_view.o: srcs/camera/camera_get_view.c \
	srcs/camera/include/camera.h srcs/math_utils/include/math_utils.h
$(O_DIR)/srcs/camera/camera_look.o: srcs/camera/camera_look.c \
	srcs/camera/include/camera.h srcs/math_utils/include/math_utils.h
$(O_DIR)/srcs/camera/camera_move.o: srcs/camera/camera_move.c \
	srcs/camera/include/camera.h srcs/math_utils/include/math_utils.h

# module events
$(O_DIR)/srcs/events/events.o: srcs/events/events.c \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h \
	srcs/events/include/events.h srcs/gl/gl.h srcs/utils/include/utils.h

# module ft::base
$(O_DIR)/libft/ft_base/ft_abs.o: libft/ft_base/ft_abs.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_assert.o: libft/ft_base/ft_assert.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_atoib.o: libft/ft_base/ft_atoib.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_bzero.o: libft/ft_base/ft_bzero.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_clock.o: libft/ft_base/ft_clock.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_emalloc.o: libft/ft_base/ft_emalloc.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_escape.o: libft/ft_base/ft_escape.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_is.o: libft/ft_base/ft_is.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_max.o: libft/ft_base/ft_max.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memcmp.o: libft/ft_base/ft_memcmp.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memcpy.o: libft/ft_base/ft_memcpy.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memdup.o: libft/ft_base/ft_memdup.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memfill.o: libft/ft_base/ft_memfill.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memmove.o: libft/ft_base/ft_memmove.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memrcpy.o: libft/ft_base/ft_memrcpy.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memset.o: libft/ft_base/ft_memset.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memstart.o: libft/ft_base/ft_memstart.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memswap.o: libft/ft_base/ft_memswap.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_min.o: libft/ft_base/ft_min.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_nanoclock.o: libft/ft_base/ft_nanoclock.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_rand.o: libft/ft_base/ft_rand.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_randbool.o: libft/ft_base/ft_randbool.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_strchri.o: libft/ft_base/ft_strchri.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_strlen.o: libft/ft_base/ft_strlen.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_sub.o: libft/ft_base/ft_sub.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_unescape.o: libft/ft_base/ft_unescape.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_widetoa.o: libft/ft_base/ft_widetoa.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_wstrconv.o: libft/ft_base/ft_wstrconv.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_wstrlen.o: libft/ft_base/ft_wstrlen.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_wstrnconv.o: libft/ft_base/ft_wstrnconv.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h

# module ft::buff
$(O_DIR)/libft/ft_buff/ft_buffclear.o: libft/ft_buff/ft_buffclear.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h
$(O_DIR)/libft/ft_buff/ft_buffget.o: libft/ft_buff/ft_buffget.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h
$(O_DIR)/libft/ft_buff/ft_parse.o: libft/ft_buff/ft_parse.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h
$(O_DIR)/libft/ft_buff/ft_parsebase.o: libft/ft_buff/ft_parsebase.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h
$(O_DIR)/libft/ft_buff/ft_parsedouble.o: libft/ft_buff/ft_parsedouble.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h
$(O_DIR)/libft/ft_buff/ft_parseendl.o: libft/ft_buff/ft_parseendl.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h
$(O_DIR)/libft/ft_buff/ft_parsef.o: libft/ft_buff/ft_parsef.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h
$(O_DIR)/libft/ft_buff/ft_parseint.o: libft/ft_buff/ft_parseint.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h
$(O_DIR)/libft/ft_buff/ft_parselong.o: libft/ft_buff/ft_parselong.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h
$(O_DIR)/libft/ft_buff/ft_parsen.o: libft/ft_buff/ft_parsen.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h
$(O_DIR)/libft/ft_buff/ft_parsenot.o: libft/ft_buff/ft_parsenot.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h
$(O_DIR)/libft/ft_buff/ft_parsespace.o: libft/ft_buff/ft_parsespace.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h
$(O_DIR)/libft/ft_buff/ft_parsestr.o: libft/ft_buff/ft_parsestr.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h
$(O_DIR)/libft/ft_buff/ft_parsewhite.o: libft/ft_buff/ft_parsewhite.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h
$(O_DIR)/libft/ft_buff/ft_readbuff.o: libft/ft_buff/ft_readbuff.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h

# module ft::count_out
$(O_DIR)/libft/ft_count_out/ft_count_out.o: libft/ft_count_out/ft_count_out.c \
	libft/ft_base/public/libft.h libft/ft_count_out/public/ft_count_out.h \
	libft/ft_out/public/ft_out.h

# module ft::get_next_line
$(O_DIR)/libft/get_next_line/get_next_line.o: \
	libft/get_next_line/get_next_line.c libft/ft_base/public/libft.h \
	libft/get_next_line/gnl_internal.h \
	libft/get_next_line/public/get_next_line.h

$(O_DIR)/libft/get_next_line/get_next_line.o: INCLUDE_FLAGS += \
	-Ilibft/get_next_line

# module ft::hmap
$(O_DIR)/libft/ft_hmap/ft_djb2.o: libft/ft_hmap/ft_djb2.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapdatas.o: libft/ft_hmap/ft_hmapdatas.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapdestroy.o: libft/ft_hmap/ft_hmapdestroy.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapget.o: libft/ft_hmap/ft_hmapget.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapkeys.o: libft/ft_hmap/ft_hmapkeys.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapnew.o: libft/ft_hmap/ft_hmapnew.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapput.o: libft/ft_hmap/ft_hmapput.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapputp.o: libft/ft_hmap/ft_hmapputp.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmaprem.o: libft/ft_hmap/ft_hmaprem.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/hmap_puth.o: libft/ft_hmap/hmap_puth.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h

$(O_DIR)/libft/ft_hmap/ft_djb2.o $(O_DIR)/libft/ft_hmap/ft_hmapdatas.o \
$(O_DIR)/libft/ft_hmap/ft_hmapdestroy.o $(O_DIR)/libft/ft_hmap/ft_hmapget.o \
$(O_DIR)/libft/ft_hmap/ft_hmapkeys.o $(O_DIR)/libft/ft_hmap/ft_hmapnew.o \
$(O_DIR)/libft/ft_hmap/ft_hmapput.o $(O_DIR)/libft/ft_hmap/ft_hmapputp.o \
$(O_DIR)/libft/ft_hmap/ft_hmaprem.o $(O_DIR)/libft/ft_hmap/hmap_puth.o: \
	INCLUDE_FLAGS += -Ilibft/ft_hmap

# module ft::list
$(O_DIR)/libft/ft_list/ft_listadd.o: libft/ft_list/ft_listadd.c \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h
$(O_DIR)/libft/ft_list/ft_listremove.o: libft/ft_list/ft_listremove.c \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h
$(O_DIR)/libft/ft_list/ft_listsort.o: libft/ft_list/ft_listsort.c \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h

# module ft::out
$(O_DIR)/libft/ft_out/ft_putchar.o: libft/ft_out/ft_putchar.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putendl.o: libft/ft_out/ft_putendl.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putfloat.o: libft/ft_out/ft_putfloat.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putint.o: libft/ft_out/ft_putint.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putnchar.o: libft/ft_out/ft_putnchar.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putpad.o: libft/ft_out/ft_putpad.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putstr.o: libft/ft_out/ft_putstr.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putsub.o: libft/ft_out/ft_putsub.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putuint.o: libft/ft_out/ft_putuint.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_write.o: libft/ft_out/ft_write.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_write_char.o: libft/ft_out/ft_write_char.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_write_nchar.o: libft/ft_out/ft_write_nchar.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/out_formats.o: libft/ft_out/out_formats.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h

$(O_DIR)/libft/ft_out/ft_putchar.o $(O_DIR)/libft/ft_out/ft_putendl.o \
$(O_DIR)/libft/ft_out/ft_putfloat.o $(O_DIR)/libft/ft_out/ft_putint.o \
$(O_DIR)/libft/ft_out/ft_putnchar.o $(O_DIR)/libft/ft_out/ft_putpad.o \
$(O_DIR)/libft/ft_out/ft_putstr.o $(O_DIR)/libft/ft_out/ft_putsub.o \
$(O_DIR)/libft/ft_out/ft_putuint.o $(O_DIR)/libft/ft_out/ft_write.o \
$(O_DIR)/libft/ft_out/ft_write_char.o $(O_DIR)/libft/ft_out/ft_write_nchar.o \
$(O_DIR)/libft/ft_out/out_formats.o: INCLUDE_FLAGS += -Ilibft/ft_out

# module ft::printf
$(O_DIR)/libft/ft_printf/args_utils.o: libft/ft_printf/args_utils.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/exec_format.o: libft/ft_printf/exec_format.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/exec_subformat.o: libft/ft_printf/exec_subformat.c \
	libft/ft_base/public/libft.h libft/ft_count_out/public/ft_count_out.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/formats/char.o: libft/ft_printf/formats/char.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/formats/int.o: libft/ft_printf/formats/int.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/formats/misc.o: libft/ft_printf/formats/misc.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/formats/str.o: libft/ft_printf/formats/str.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_out.o: libft/ft_printf/ft_out.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_printf.o: libft/ft_printf/ft_printf.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_putf.o: libft/ft_printf/ft_putf.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_vprintf.o: libft/ft_printf/ft_vprintf.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h

$(O_DIR)/libft/ft_printf/args_utils.o $(O_DIR)/libft/ft_printf/exec_format.o \
$(O_DIR)/libft/ft_printf/exec_subformat.o \
$(O_DIR)/libft/ft_printf/formats/char.o $(O_DIR)/libft/ft_printf/formats/int.o \
$(O_DIR)/libft/ft_printf/formats/misc.o $(O_DIR)/libft/ft_printf/formats/str.o \
$(O_DIR)/libft/ft_printf/ft_out.o $(O_DIR)/libft/ft_printf/ft_printf.o \
$(O_DIR)/libft/ft_printf/ft_putf.o $(O_DIR)/libft/ft_printf/ft_vprintf.o: \
	INCLUDE_FLAGS += -Ilibft/ft_printf

# module ft::sub
$(O_DIR)/libft/ft_sub/ft_subchr.o: libft/ft_sub/ft_subchr.c \
	libft/ft_base/public/libft.h libft/ft_sub/public/ft_sub.h
$(O_DIR)/libft/ft_sub/ft_subcount.o: libft/ft_sub/ft_subcount.c \
	libft/ft_base/public/libft.h libft/ft_sub/public/ft_sub.h
$(O_DIR)/libft/ft_sub/ft_subequ.o: libft/ft_sub/ft_subequ.c \
	libft/ft_base/public/libft.h libft/ft_sub/public/ft_sub.h
$(O_DIR)/libft/ft_sub/ft_subextract.o: libft/ft_sub/ft_subextract.c \
	libft/ft_base/public/libft.h libft/ft_sub/public/ft_sub.h
$(O_DIR)/libft/ft_sub/ft_subfloat.o: libft/ft_sub/ft_subfloat.c \
	libft/ft_base/public/libft.h libft/ft_sub/public/ft_sub.h
$(O_DIR)/libft/ft_sub/ft_subindex.o: libft/ft_sub/ft_subindex.c \
	libft/ft_base/public/libft.h libft/ft_sub/public/ft_sub.h
$(O_DIR)/libft/ft_sub/ft_subint.o: libft/ft_sub/ft_subint.c \
	libft/ft_base/public/libft.h libft/ft_sub/public/ft_sub.h
$(O_DIR)/libft/ft_sub/ft_subnext.o: libft/ft_sub/ft_subnext.c \
	libft/ft_base/public/libft.h libft/ft_sub/public/ft_sub.h
$(O_DIR)/libft/ft_sub/ft_subnextc.o: libft/ft_sub/ft_subnextc.c \
	libft/ft_base/public/libft.h libft/ft_sub/public/ft_sub.h
$(O_DIR)/libft/ft_sub/ft_subsub.o: libft/ft_sub/ft_subsub.c \
	libft/ft_base/public/libft.h libft/ft_sub/public/ft_sub.h
$(O_DIR)/libft/ft_sub/ft_subtrim.o: libft/ft_sub/ft_subtrim.c \
	libft/ft_base/public/libft.h libft/ft_sub/public/ft_sub.h
$(O_DIR)/libft/ft_sub/ft_subtriml.o: libft/ft_sub/ft_subtriml.c \
	libft/ft_base/public/libft.h libft/ft_sub/public/ft_sub.h
$(O_DIR)/libft/ft_sub/ft_subtrimr.o: libft/ft_sub/ft_subtrimr.c \
	libft/ft_base/public/libft.h libft/ft_sub/public/ft_sub.h

# module ft::vector
$(O_DIR)/libft/ft_vector/ft_vclear.o: libft/ft_vector/ft_vclear.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h
$(O_DIR)/libft/ft_vector/ft_vpush_back.o: libft/ft_vector/ft_vpush_back.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h
$(O_DIR)/libft/ft_vector/ft_vremove.o: libft/ft_vector/ft_vremove.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h
$(O_DIR)/libft/ft_vector/ft_vreserve.o: libft/ft_vector/ft_vreserve.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h

# module gl
ifeq ($(shell uname),Darwin)
  BASE_FLAGS += -DMAC_OS_MODE=1
  LINK_FLAGS += -lglfw3 -framework OpenGL
else
  LINK_FLAGS += -lglfw -lGL -lGLEW
endif

# module main
$(O_DIR)/srcs/main/callbacks.o: srcs/main/callbacks.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h \
	srcs/anim/include/anim.h srcs/camera/include/camera.h \
	srcs/events/include/events.h srcs/gl/gl.h srcs/main/include/main.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/renderer/include/public/renderer.h \
	srcs/texture/texture.h srcs/transform/include/transform.h
$(O_DIR)/srcs/main/init_window.o: srcs/main/init_window.c \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h \
	libft/ft_vector/public/ft_vector.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/gl/gl.h srcs/main/include/main.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/renderer/include/public/renderer.h \
	srcs/texture/texture.h srcs/transform/include/transform.h \
	srcs/utils/include/utils.h
$(O_DIR)/srcs/main/main.o: srcs/main/main.c libft/ft_base/public/libft.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_list/public/ft_list.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/public/ft_printf.h \
	libft/ft_vector/public/ft_vector.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/events/include/events.h srcs/gl/gl.h \
	srcs/main/include/main.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mesh_loader/include/public/mesh_loader.h \
	srcs/mtl/mtl.h srcs/obj/include/obj.h srcs/obj_anim/include/obj_anim.h \
	srcs/renderer/include/public/renderer.h srcs/shader/shader.h \
	srcs/texture/texture.h srcs/transform/include/transform.h \
	srcs/utils/include/utils.h
$(O_DIR)/srcs/main/motions.o: srcs/main/motions.c libft/ft_base/public/libft.h \
	libft/ft_vector/public/ft_vector.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/gl/gl.h srcs/main/include/main.h \
	srcs/main/include/motions.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mtl/mtl.h srcs/obj/include/obj.h \
	srcs/renderer/include/public/renderer.h srcs/texture/texture.h \
	srcs/transform/include/transform.h

$(O_DIR)/srcs/main/callbacks.o $(O_DIR)/srcs/main/init_window.o \
$(O_DIR)/srcs/main/main.o $(O_DIR)/srcs/main/motions.o: MDR += lol
$(O_DIR)/srcs/main/callbacks.o $(O_DIR)/srcs/main/init_window.o \
$(O_DIR)/srcs/main/main.o $(O_DIR)/srcs/main/motions.o: INCLUDE_FLAGS += \
	-Isrcs/main/include

# module math_utils
$(O_DIR)/srcs/math_utils/ft_mat4look_at.o: srcs/math_utils/ft_mat4look_at.c \
	srcs/math_utils/include/math_utils.h
$(O_DIR)/srcs/math_utils/ft_mat4mult.o: srcs/math_utils/ft_mat4mult.c \
	srcs/math_utils/include/math_utils.h
$(O_DIR)/srcs/math_utils/ft_mat4perspective.o: \
	srcs/math_utils/ft_mat4perspective.c srcs/math_utils/include/math_utils.h
$(O_DIR)/srcs/math_utils/ft_mat4reflect.o: srcs/math_utils/ft_mat4reflect.c \
	srcs/math_utils/include/math_utils.h
$(O_DIR)/srcs/math_utils/ft_mat4rotate.o: srcs/math_utils/ft_mat4rotate.c \
	srcs/math_utils/include/math_utils.h
$(O_DIR)/srcs/math_utils/ft_mat4scale.o: srcs/math_utils/ft_mat4scale.c \
	srcs/math_utils/include/math_utils.h
$(O_DIR)/srcs/math_utils/ft_mat4shear.o: srcs/math_utils/ft_mat4shear.c \
	srcs/math_utils/include/math_utils.h
$(O_DIR)/srcs/math_utils/ft_mat4translate.o: \
	srcs/math_utils/ft_mat4translate.c srcs/math_utils/include/math_utils.h
$(O_DIR)/srcs/math_utils/ft_mat4transpose.o: \
	srcs/math_utils/ft_mat4transpose.c srcs/math_utils/include/math_utils.h
$(O_DIR)/srcs/math_utils/ft_vec3cross.o: srcs/math_utils/ft_vec3cross.c \
	srcs/math_utils/include/math_utils.h
$(O_DIR)/srcs/math_utils/ft_vec3dot.o: srcs/math_utils/ft_vec3dot.c \
	srcs/math_utils/include/math_utils.h
$(O_DIR)/srcs/math_utils/ft_vec3front.o: srcs/math_utils/ft_vec3front.c \
	srcs/math_utils/include/math_utils.h
$(O_DIR)/srcs/math_utils/ft_vec3norm.o: srcs/math_utils/ft_vec3norm.c \
	srcs/math_utils/include/math_utils.h
$(O_DIR)/srcs/math_utils/ft_vec3rotate.o: srcs/math_utils/ft_vec3rotate.c \
	srcs/math_utils/include/math_utils.h
$(O_DIR)/srcs/math_utils/ft_vec3sub.o: srcs/math_utils/ft_vec3sub.c \
	srcs/math_utils/include/math_utils.h

# module mesh

# module mesh_loader
$(O_DIR)/srcs/mesh_loader/build_mesh.o: srcs/mesh_loader/build_mesh.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_list/public/ft_list.h libft/ft_vector/public/ft_vector.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h \
	srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h srcs/utils/include/utils.h
$(O_DIR)/srcs/mesh_loader/build_mtl.o: srcs/mesh_loader/build_mtl.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_vector/public/ft_vector.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h
$(O_DIR)/srcs/mesh_loader/load_mesh.o: srcs/mesh_loader/load_mesh.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/public/ft_printf.h \
	libft/ft_vector/public/ft_vector.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h
$(O_DIR)/srcs/mesh_loader/parse_mesh.o: srcs/mesh_loader/parse_mesh.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_list/public/ft_list.h libft/ft_sub/public/ft_sub.h \
	libft/ft_vector/public/ft_vector.h \
	libft/get_next_line/public/get_next_line.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h \
	srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h srcs/utils/include/utils.h
$(O_DIR)/srcs/mesh_loader/parse_mesh_tokens.o: \
	srcs/mesh_loader/parse_mesh_tokens.c libft/ft_base/public/libft.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_list/public/ft_list.h \
	libft/ft_sub/public/ft_sub.h libft/ft_vector/public/ft_vector.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h \
	srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h srcs/utils/include/utils.h
$(O_DIR)/srcs/mesh_loader/parse_mesh_tokens_mtl.o: \
	srcs/mesh_loader/parse_mesh_tokens_mtl.c libft/ft_base/public/libft.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_list/public/ft_list.h \
	libft/ft_sub/public/ft_sub.h libft/ft_vector/public/ft_vector.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h \
	srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/mtl_loader/include/public/mtl_loader.h srcs/texture/texture.h \
	srcs/utils/include/utils.h
$(O_DIR)/srcs/mesh_loader/send_mesh.o: srcs/mesh_loader/send_mesh.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_vector/public/ft_vector.h srcs/gl/gl.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h \
	srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h

$(O_DIR)/srcs/mesh_loader/build_mesh.o $(O_DIR)/srcs/mesh_loader/build_mtl.o \
$(O_DIR)/srcs/mesh_loader/load_mesh.o $(O_DIR)/srcs/mesh_loader/parse_mesh.o \
$(O_DIR)/srcs/mesh_loader/parse_mesh_tokens.o \
$(O_DIR)/srcs/mesh_loader/parse_mesh_tokens_mtl.o \
$(O_DIR)/srcs/mesh_loader/send_mesh.o: INCLUDE_FLAGS += \
	-Isrcs/mesh_loader/include

# module mtl

# module mtl_loader
$(O_DIR)/srcs/mtl_loader/load_mtl.o: srcs/mtl_loader/load_mtl.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h srcs/math_utils/include/math_utils.h \
	srcs/mtl/mtl.h srcs/mtl_loader/include/internal.h \
	srcs/mtl_loader/include/public/mtl_loader.h srcs/texture/texture.h \
	srcs/utils/include/utils.h
$(O_DIR)/srcs/mtl_loader/parse_mtl.o: srcs/mtl_loader/parse_mtl.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_list/public/ft_list.h libft/ft_sub/public/ft_sub.h \
	libft/get_next_line/public/get_next_line.h \
	srcs/math_utils/include/math_utils.h srcs/mtl/mtl.h \
	srcs/mtl_loader/include/internal.h \
	srcs/mtl_loader/include/public/mtl_loader.h srcs/texture/texture.h \
	srcs/utils/include/utils.h
$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens.o: \
	srcs/mtl_loader/parse_mtl_tokens.c libft/ft_base/public/libft.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_list/public/ft_list.h \
	libft/ft_sub/public/ft_sub.h srcs/math_utils/include/math_utils.h \
	srcs/mtl/mtl.h srcs/mtl_loader/include/internal.h \
	srcs/mtl_loader/include/public/mtl_loader.h srcs/texture/texture.h \
	srcs/utils/include/utils.h
$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens_map.o: \
	srcs/mtl_loader/parse_mtl_tokens_map.c libft/ft_base/public/libft.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_sub/public/ft_sub.h \
	srcs/math_utils/include/math_utils.h srcs/mtl/mtl.h \
	srcs/mtl_loader/include/internal.h \
	srcs/mtl_loader/include/public/mtl_loader.h srcs/texture/texture.h \
	srcs/texture_loader/include/public/texture_loader.h

$(O_DIR)/srcs/mtl_loader/load_mtl.o $(O_DIR)/srcs/mtl_loader/parse_mtl.o \
$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens.o \
$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens_map.o: INCLUDE_FLAGS += \
	-Isrcs/mtl_loader/include

# module obj

# module obj_anim
$(O_DIR)/srcs/obj_anim/anim_c_move.o: srcs/obj_anim/anim_c_move.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mtl/mtl.h srcs/obj/include/obj.h \
	srcs/obj_anim/include/obj_anim.h srcs/texture/texture.h \
	srcs/transform/include/transform.h
$(O_DIR)/srcs/obj_anim/anim_c_rot.o: srcs/obj_anim/anim_c_rot.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mtl/mtl.h srcs/obj/include/obj.h \
	srcs/obj_anim/include/obj_anim.h srcs/texture/texture.h \
	srcs/transform/include/transform.h
$(O_DIR)/srcs/obj_anim/anim_c_scale.o: srcs/obj_anim/anim_c_scale.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mtl/mtl.h srcs/obj/include/obj.h \
	srcs/obj_anim/include/obj_anim.h srcs/texture/texture.h \
	srcs/transform/include/transform.h
$(O_DIR)/srcs/obj_anim/anim_c_shear.o: srcs/obj_anim/anim_c_shear.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mtl/mtl.h srcs/obj/include/obj.h \
	srcs/obj_anim/include/obj_anim.h srcs/texture/texture.h \
	srcs/transform/include/transform.h

# module renderer
$(O_DIR)/srcs/renderer/depth_renderer.o: srcs/renderer/depth_renderer.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	srcs/anim/include/anim.h srcs/camera/include/camera.h srcs/gl/gl.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/renderer/include/public/renderer.h \
	srcs/renderer/include/renderers.h srcs/shader/shader.h \
	srcs/shader_loader/include/public/shader_loader.h srcs/texture/texture.h \
	srcs/transform/include/transform.h
$(O_DIR)/srcs/renderer/renderers.o: srcs/renderer/renderers.c \
	libft/ft_base/public/libft.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mtl/mtl.h srcs/obj/include/obj.h \
	srcs/renderer/include/public/renderer.h srcs/renderer/include/renderers.h \
	srcs/texture/texture.h srcs/transform/include/transform.h
$(O_DIR)/srcs/renderer/simple_renderer.o: srcs/renderer/simple_renderer.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_list/public/ft_list.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/gl/gl.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/renderer/include/public/renderer.h \
	srcs/shader/shader.h srcs/shader_loader/include/public/shader_loader.h \
	srcs/texture/texture.h srcs/transform/include/transform.h \
	srcs/utils/include/utils.h

$(O_DIR)/srcs/renderer/depth_renderer.o $(O_DIR)/srcs/renderer/renderers.o \
$(O_DIR)/srcs/renderer/simple_renderer.o: INCLUDE_FLAGS += \
	-Isrcs/renderer/include

# module shader

# module shader_loader
$(O_DIR)/srcs/shader_loader/compile_shader.o: \
	srcs/shader_loader/compile_shader.c libft/ft_base/public/ft_colors.h \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h srcs/gl/gl.h srcs/shader/shader.h \
	srcs/shader_loader/include/internal.h \
	srcs/shader_loader/include/public/shader_loader.h
$(O_DIR)/srcs/shader_loader/load_shader.o: srcs/shader_loader/load_shader.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_list/public/ft_list.h srcs/gl/gl.h srcs/shader/shader.h \
	srcs/shader_loader/include/internal.h \
	srcs/shader_loader/include/public/shader_loader.h \
	srcs/utils/include/utils.h
$(O_DIR)/srcs/shader_loader/load_uniforms.o: \
	srcs/shader_loader/load_uniforms.c libft/ft_base/public/libft.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_list/public/ft_list.h srcs/gl/gl.h \
	srcs/shader/shader.h srcs/shader_loader/include/internal.h \
	srcs/shader_loader/include/public/shader_loader.h \
	srcs/utils/include/utils.h
$(O_DIR)/srcs/shader_loader/read_shader.o: srcs/shader_loader/read_shader.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_list/public/ft_list.h libft/ft_sub/public/ft_sub.h \
	libft/get_next_line/public/get_next_line.h srcs/gl/gl.h \
	srcs/shader/shader.h srcs/shader_loader/include/internal.h \
	srcs/shader_loader/include/public/shader_loader.h \
	srcs/utils/include/utils.h
$(O_DIR)/srcs/shader_loader/shader_get_uniform.o: \
	srcs/shader_loader/shader_get_uniform.c libft/ft_base/public/libft.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_list/public/ft_list.h \
	srcs/shader/shader.h srcs/shader_loader/include/internal.h \
	srcs/shader_loader/include/public/shader_loader.h

$(O_DIR)/srcs/shader_loader/compile_shader.o \
$(O_DIR)/srcs/shader_loader/load_shader.o \
$(O_DIR)/srcs/shader_loader/load_uniforms.o \
$(O_DIR)/srcs/shader_loader/read_shader.o \
$(O_DIR)/srcs/shader_loader/shader_get_uniform.o: INCLUDE_FLAGS += \
	-Isrcs/shader_loader/include

# module texture

# module texture_loader
$(O_DIR)/srcs/texture_loader/ft_loadimage.o: \
	srcs/texture_loader/ft_loadimage.c libft/ft_base/public/libft.h \
	libft/ft_buff/public/ft_buff.h srcs/texture_loader/include/ft_img.h
$(O_DIR)/srcs/texture_loader/load_texture.o: \
	srcs/texture_loader/load_texture.c libft/ft_base/public/libft.h \
	libft/ft_buff/public/ft_buff.h libft/ft_hmap/public/ft_hmap.h srcs/gl/gl.h \
	srcs/texture/texture.h srcs/texture_loader/include/ft_img.h \
	srcs/texture_loader/include/internal.h \
	srcs/texture_loader/include/public/texture_loader.h
$(O_DIR)/srcs/texture_loader/tga_parser.o: srcs/texture_loader/tga_parser.c \
	libft/ft_base/public/libft.h libft/ft_buff/public/ft_buff.h \
	libft/ft_list/public/ft_list.h srcs/texture_loader/include/ft_img.h \
	srcs/utils/include/utils.h

$(O_DIR)/srcs/texture_loader/ft_loadimage.o \
$(O_DIR)/srcs/texture_loader/load_texture.o \
$(O_DIR)/srcs/texture_loader/tga_parser.o: INCLUDE_FLAGS += \
	-Isrcs/texture_loader/include

# module transform
$(O_DIR)/srcs/transform/ft_transform_get.o: srcs/transform/ft_transform_get.c \
	srcs/math_utils/include/math_utils.h srcs/transform/include/transform.h
$(O_DIR)/srcs/transform/ft_transform_move.o: \
	srcs/transform/ft_transform_move.c srcs/math_utils/include/math_utils.h \
	srcs/transform/include/transform.h
$(O_DIR)/srcs/transform/ft_transform_reflect.o: \
	srcs/transform/ft_transform_reflect.c srcs/math_utils/include/math_utils.h \
	srcs/transform/include/transform.h
$(O_DIR)/srcs/transform/ft_transform_rotate.o: \
	srcs/transform/ft_transform_rotate.c srcs/math_utils/include/math_utils.h \
	srcs/transform/include/transform.h
$(O_DIR)/srcs/transform/ft_transform_scale.o: \
	srcs/transform/ft_transform_scale.c srcs/math_utils/include/math_utils.h \
	srcs/transform/include/transform.h
$(O_DIR)/srcs/transform/ft_transform_shear.o: \
	srcs/transform/ft_transform_shear.c srcs/math_utils/include/math_utils.h \
	srcs/transform/include/transform.h

# module utils
$(O_DIR)/srcs/utils/fps.o: srcs/utils/fps.c libft/ft_base/public/libft.h \
	libft/ft_list/public/ft_list.h srcs/utils/include/utils.h
$(O_DIR)/srcs/utils/ft_error.o: srcs/utils/ft_error.c \
	libft/ft_base/public/ft_colors.h libft/ft_base/public/libft.h \
	libft/ft_list/public/ft_list.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h \
	srcs/utils/include/utils.h
$(O_DIR)/srcs/utils/ft_listremove_next.o: srcs/utils/ft_listremove_next.c \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h \
	srcs/utils/include/utils.h
$(O_DIR)/srcs/utils/ft_subends.o: srcs/utils/ft_subends.c \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h \
	srcs/utils/include/utils.h
$(O_DIR)/srcs/utils/ft_substart.o: srcs/utils/ft_substart.c \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h \
	srcs/utils/include/utils.h
$(O_DIR)/srcs/utils/parse_fvec.o: srcs/utils/parse_fvec.c \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/public/ft_printf.h \
	libft/ft_sub/public/ft_sub.h srcs/utils/include/utils.h

# obj dirs
$(O_DIR)/libft/ft_list/ft_listsort.o $(O_DIR)/libft/ft_list/ft_listadd.o \
$(O_DIR)/libft/ft_list/ft_listremove.o: | $(O_DIR)/libft/ft_list/
$(O_DIR)/libft/ft_sub/ft_subequ.o $(O_DIR)/libft/ft_sub/ft_subtrimr.o \
$(O_DIR)/libft/ft_sub/ft_subextract.o $(O_DIR)/libft/ft_sub/ft_subint.o \
$(O_DIR)/libft/ft_sub/ft_subchr.o $(O_DIR)/libft/ft_sub/ft_subnext.o \
$(O_DIR)/libft/ft_sub/ft_subtriml.o $(O_DIR)/libft/ft_sub/ft_subnextc.o \
$(O_DIR)/libft/ft_sub/ft_subindex.o $(O_DIR)/libft/ft_sub/ft_subfloat.o \
$(O_DIR)/libft/ft_sub/ft_subcount.o $(O_DIR)/libft/ft_sub/ft_subsub.o \
$(O_DIR)/libft/ft_sub/ft_subtrim.o: | $(O_DIR)/libft/ft_sub/
$(O_DIR)/srcs/transform/ft_transform_scale.o \
$(O_DIR)/srcs/transform/ft_transform_shear.o \
$(O_DIR)/srcs/transform/ft_transform_reflect.o \
$(O_DIR)/srcs/transform/ft_transform_rotate.o \
$(O_DIR)/srcs/transform/ft_transform_get.o \
$(O_DIR)/srcs/transform/ft_transform_move.o: | $(O_DIR)/srcs/transform/
$(O_DIR)/libft/ft_count_out/ft_count_out.o: | $(O_DIR)/libft/ft_count_out/
$(O_DIR)/libft/ft_printf/exec_subformat.o \
$(O_DIR)/libft/ft_printf/args_utils.o $(O_DIR)/libft/ft_printf/formats/int.o \
$(O_DIR)/libft/ft_printf/ft_out.o $(O_DIR)/libft/ft_printf/exec_format.o \
$(O_DIR)/libft/ft_printf/ft_putf.o $(O_DIR)/libft/ft_printf/formats/str.o \
$(O_DIR)/libft/ft_printf/ft_vprintf.o $(O_DIR)/libft/ft_printf/ft_printf.o \
$(O_DIR)/libft/ft_printf/formats/misc.o \
$(O_DIR)/libft/ft_printf/formats/char.o: | $(O_DIR)/libft/ft_printf/ \
	$(O_DIR)/libft/ft_printf/formats/
$(O_DIR)/srcs/math_utils/ft_vec3rotate.o \
$(O_DIR)/srcs/math_utils/ft_mat4transpose.o \
$(O_DIR)/srcs/math_utils/ft_mat4scale.o \
$(O_DIR)/srcs/math_utils/ft_mat4rotate.o $(O_DIR)/srcs/math_utils/ft_vec3sub.o \
$(O_DIR)/srcs/math_utils/ft_mat4mult.o $(O_DIR)/srcs/math_utils/ft_vec3front.o \
$(O_DIR)/srcs/math_utils/ft_mat4translate.o \
$(O_DIR)/srcs/math_utils/ft_mat4look_at.o \
$(O_DIR)/srcs/math_utils/ft_mat4shear.o $(O_DIR)/srcs/math_utils/ft_vec3dot.o \
$(O_DIR)/srcs/math_utils/ft_mat4reflect.o \
$(O_DIR)/srcs/math_utils/ft_mat4perspective.o \
$(O_DIR)/srcs/math_utils/ft_vec3cross.o $(O_DIR)/srcs/math_utils/ft_vec3norm.o: \
	| $(O_DIR)/srcs/math_utils/
$(O_DIR)/srcs/renderer/simple_renderer.o $(O_DIR)/srcs/renderer/renderers.o \
$(O_DIR)/srcs/renderer/depth_renderer.o: | $(O_DIR)/srcs/renderer/
$(O_DIR)/srcs/shader_loader/load_shader.o \
$(O_DIR)/srcs/shader_loader/compile_shader.o \
$(O_DIR)/srcs/shader_loader/load_uniforms.o \
$(O_DIR)/srcs/shader_loader/read_shader.o \
$(O_DIR)/srcs/shader_loader/shader_get_uniform.o: | \
	$(O_DIR)/srcs/shader_loader/
$(O_DIR)/srcs/anim/smooth_out.o $(O_DIR)/srcs/anim/smooth_bounce.o \
$(O_DIR)/srcs/anim/smooth_elastic.o $(O_DIR)/srcs/anim/anim_start.o \
$(O_DIR)/srcs/anim/smooth_back_in_out.o $(O_DIR)/srcs/anim/smooth_linear.o \
$(O_DIR)/srcs/anim/smooth_back_out.o $(O_DIR)/srcs/anim/smooth_back_in.o \
$(O_DIR)/srcs/anim/anim_update.o $(O_DIR)/srcs/anim/smooth_in.o \
$(O_DIR)/srcs/anim/smooth_in_out.o: | $(O_DIR)/srcs/anim/
$(O_DIR)/libft/ft_vector/ft_vpush_back.o $(O_DIR)/libft/ft_vector/ft_vclear.o \
$(O_DIR)/libft/ft_vector/ft_vreserve.o $(O_DIR)/libft/ft_vector/ft_vremove.o: \
	| $(O_DIR)/libft/ft_vector/
$(O_DIR)/libft/ft_out/ft_write_char.o $(O_DIR)/libft/ft_out/ft_putuint.o \
$(O_DIR)/libft/ft_out/out_formats.o $(O_DIR)/libft/ft_out/ft_putnchar.o \
$(O_DIR)/libft/ft_out/ft_putint.o $(O_DIR)/libft/ft_out/ft_putchar.o \
$(O_DIR)/libft/ft_out/ft_putendl.o $(O_DIR)/libft/ft_out/ft_putsub.o \
$(O_DIR)/libft/ft_out/ft_putstr.o $(O_DIR)/libft/ft_out/ft_write.o \
$(O_DIR)/libft/ft_out/ft_write_nchar.o $(O_DIR)/libft/ft_out/ft_putfloat.o \
$(O_DIR)/libft/ft_out/ft_putpad.o: | $(O_DIR)/libft/ft_out/
$(O_DIR)/libft/get_next_line/get_next_line.o: | $(O_DIR)/libft/get_next_line/
$(O_DIR)/libft/ft_buff/ft_parsef.o $(O_DIR)/libft/ft_buff/ft_parseint.o \
$(O_DIR)/libft/ft_buff/ft_readbuff.o $(O_DIR)/libft/ft_buff/ft_parselong.o \
$(O_DIR)/libft/ft_buff/ft_parse.o $(O_DIR)/libft/ft_buff/ft_parsedouble.o \
$(O_DIR)/libft/ft_buff/ft_buffget.o $(O_DIR)/libft/ft_buff/ft_parseendl.o \
$(O_DIR)/libft/ft_buff/ft_parsen.o $(O_DIR)/libft/ft_buff/ft_buffclear.o \
$(O_DIR)/libft/ft_buff/ft_parsenot.o $(O_DIR)/libft/ft_buff/ft_parsebase.o \
$(O_DIR)/libft/ft_buff/ft_parsewhite.o $(O_DIR)/libft/ft_buff/ft_parsestr.o \
$(O_DIR)/libft/ft_buff/ft_parsespace.o: | $(O_DIR)/libft/ft_buff/
$(O_DIR)/srcs/mtl_loader/load_mtl.o \
$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens.o \
$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens_map.o \
$(O_DIR)/srcs/mtl_loader/parse_mtl.o: | $(O_DIR)/srcs/mtl_loader/
$(O_DIR)/srcs/main/init_window.o $(O_DIR)/srcs/main/callbacks.o \
$(O_DIR)/srcs/main/main.o $(O_DIR)/srcs/main/motions.o: | $(O_DIR)/srcs/main/
$(O_DIR)/srcs/camera/camera_look.o $(O_DIR)/srcs/camera/camera_move.o \
$(O_DIR)/srcs/camera/camera_get_view.o: | $(O_DIR)/srcs/camera/
$(O_DIR)/libft/ft_hmap/ft_hmapnew.o $(O_DIR)/libft/ft_hmap/ft_hmapkeys.o \
$(O_DIR)/libft/ft_hmap/ft_hmapdestroy.o $(O_DIR)/libft/ft_hmap/ft_hmapget.o \
$(O_DIR)/libft/ft_hmap/ft_hmaprem.o $(O_DIR)/libft/ft_hmap/ft_hmapdatas.o \
$(O_DIR)/libft/ft_hmap/hmap_puth.o $(O_DIR)/libft/ft_hmap/ft_hmapput.o \
$(O_DIR)/libft/ft_hmap/ft_hmapputp.o $(O_DIR)/libft/ft_hmap/ft_djb2.o: | \
	$(O_DIR)/libft/ft_hmap/
$(O_DIR)/srcs/utils/parse_fvec.o $(O_DIR)/srcs/utils/ft_error.o \
$(O_DIR)/srcs/utils/ft_listremove_next.o $(O_DIR)/srcs/utils/ft_substart.o \
$(O_DIR)/srcs/utils/fps.o $(O_DIR)/srcs/utils/ft_subends.o: | \
	$(O_DIR)/srcs/utils/
$(O_DIR)/srcs/obj_anim/anim_c_scale.o $(O_DIR)/srcs/obj_anim/anim_c_rot.o \
$(O_DIR)/srcs/obj_anim/anim_c_move.o $(O_DIR)/srcs/obj_anim/anim_c_shear.o: | \
	$(O_DIR)/srcs/obj_anim/
$(O_DIR)/libft/ft_base/ft_unescape.o $(O_DIR)/libft/ft_base/ft_memfill.o \
$(O_DIR)/libft/ft_base/ft_memcpy.o $(O_DIR)/libft/ft_base/ft_atoib.o \
$(O_DIR)/libft/ft_base/ft_sub.o $(O_DIR)/libft/ft_base/ft_bzero.o \
$(O_DIR)/libft/ft_base/ft_abs.o $(O_DIR)/libft/ft_base/ft_strchri.o \
$(O_DIR)/libft/ft_base/ft_nanoclock.o $(O_DIR)/libft/ft_base/ft_memdup.o \
$(O_DIR)/libft/ft_base/ft_wstrconv.o $(O_DIR)/libft/ft_base/ft_min.o \
$(O_DIR)/libft/ft_base/ft_memmove.o $(O_DIR)/libft/ft_base/ft_widetoa.o \
$(O_DIR)/libft/ft_base/ft_clock.o $(O_DIR)/libft/ft_base/ft_memswap.o \
$(O_DIR)/libft/ft_base/ft_max.o $(O_DIR)/libft/ft_base/ft_memrcpy.o \
$(O_DIR)/libft/ft_base/ft_wstrlen.o $(O_DIR)/libft/ft_base/ft_rand.o \
$(O_DIR)/libft/ft_base/ft_memstart.o $(O_DIR)/libft/ft_base/ft_assert.o \
$(O_DIR)/libft/ft_base/ft_wstrnconv.o $(O_DIR)/libft/ft_base/ft_emalloc.o \
$(O_DIR)/libft/ft_base/ft_randbool.o $(O_DIR)/libft/ft_base/ft_is.o \
$(O_DIR)/libft/ft_base/ft_memcmp.o $(O_DIR)/libft/ft_base/ft_memset.o \
$(O_DIR)/libft/ft_base/ft_strlen.o $(O_DIR)/libft/ft_base/ft_escape.o: | \
	$(O_DIR)/libft/ft_base/
$(O_DIR)/srcs/mesh_loader/build_mesh.o $(O_DIR)/srcs/mesh_loader/parse_mesh.o \
$(O_DIR)/srcs/mesh_loader/send_mesh.o $(O_DIR)/srcs/mesh_loader/build_mtl.o \
$(O_DIR)/srcs/mesh_loader/parse_mesh_tokens_mtl.o \
$(O_DIR)/srcs/mesh_loader/load_mesh.o \
$(O_DIR)/srcs/mesh_loader/parse_mesh_tokens.o: | $(O_DIR)/srcs/mesh_loader/
$(O_DIR)/srcs/events/events.o: | $(O_DIR)/srcs/events/
$(O_DIR)/srcs/texture_loader/load_texture.o \
$(O_DIR)/srcs/texture_loader/ft_loadimage.o \
$(O_DIR)/srcs/texture_loader/tga_parser.o: | $(O_DIR)/srcs/texture_loader/

# public links
$(O_DIR)/_public/anim.h: srcs/anim/include/anim.h
$(O_DIR)/_public/camera.h: srcs/camera/include/camera.h
$(O_DIR)/_public/events.h: srcs/events/include/events.h
$(O_DIR)/_public/ft/ft_buff.h: libft/ft_buff/public/ft_buff.h
$(O_DIR)/_public/ft/ft_colors.h: libft/ft_base/public/ft_colors.h
$(O_DIR)/_public/ft/ft_count_out.h: libft/ft_count_out/public/ft_count_out.h
$(O_DIR)/_public/ft/ft_hmap.h: libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/_public/ft/ft_list.h: libft/ft_list/public/ft_list.h
$(O_DIR)/_public/ft/ft_out.h: libft/ft_out/public/ft_out.h
$(O_DIR)/_public/ft/ft_printf.h: libft/ft_printf/public/ft_printf.h
$(O_DIR)/_public/ft/ft_sub.h: libft/ft_sub/public/ft_sub.h
$(O_DIR)/_public/ft/ft_vector.h: libft/ft_vector/public/ft_vector.h
$(O_DIR)/_public/ft/ft_vprintf.h: libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/_public/ft/ft_wchar.h: libft/ft_base/public/ft_wchar.h
$(O_DIR)/_public/ft/get_next_line.h: \
libft/get_next_line/public/get_next_line.h
$(O_DIR)/_public/ft/libft.h: libft/ft_base/public/libft.h
$(O_DIR)/_public/gl.h: srcs/gl/gl.h
$(O_DIR)/_public/math_utils.h: srcs/math_utils/include/math_utils.h
$(O_DIR)/_public/mesh.h: srcs/mesh/mesh.h
$(O_DIR)/_public/mesh_loader.h: srcs/mesh_loader/include/public/mesh_loader.h
$(O_DIR)/_public/mtl.h: srcs/mtl/mtl.h
$(O_DIR)/_public/mtl_loader.h: srcs/mtl_loader/include/public/mtl_loader.h
$(O_DIR)/_public/obj.h: srcs/obj/include/obj.h
$(O_DIR)/_public/obj_anim.h: srcs/obj_anim/include/obj_anim.h
$(O_DIR)/_public/renderer.h: srcs/renderer/include/public/renderer.h
$(O_DIR)/_public/shader.h: srcs/shader/shader.h
$(O_DIR)/_public/shader_loader.h: \
srcs/shader_loader/include/public/shader_loader.h
$(O_DIR)/_public/texture.h: srcs/texture/texture.h
$(O_DIR)/_public/texture_loader.h: \
srcs/texture_loader/include/public/texture_loader.h
$(O_DIR)/_public/transform.h: srcs/transform/include/transform.h
$(O_DIR)/_public/utils.h: srcs/utils/include/utils.h
