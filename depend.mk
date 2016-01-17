INCLUDE_FLAGS += -I$(O_DIR)/_public
LINK_FLAGS += -lm
OBJ_DIR_TREE += $(O_DIR)/srcs/utils/ $(O_DIR)/srcs/texture_loader/ \
	$(O_DIR)/srcs/shader_loader/ $(O_DIR)/srcs/render/ $(O_DIR)/srcs/obj_anim/ \
	$(O_DIR)/srcs/obj/ $(O_DIR)/srcs/mtl_loader/ $(O_DIR)/srcs/mesh_loader/ \
	$(O_DIR)/srcs/main/ $(O_DIR)/srcs/ft_image_loader/ $(O_DIR)/srcs/events/ \
	$(O_DIR)/srcs/camera/ $(O_DIR)/srcs/anim/ $(O_DIR)/srcs/ \
	$(O_DIR)/libft/get_next_line/ $(O_DIR)/libft/ft_vector/ \
	$(O_DIR)/libft/ft_printf/formats/ $(O_DIR)/libft/ft_printf/ \
	$(O_DIR)/libft/ft_out/ $(O_DIR)/libft/ft_math/ $(O_DIR)/libft/ft_list/ \
	$(O_DIR)/libft/ft_in/ $(O_DIR)/libft/ft_hmap/ $(O_DIR)/libft/ft_dstr/ \
	$(O_DIR)/libft/ft_base/ $(O_DIR)/libft/ $(O_DIR)/_public/ft/ \
	$(O_DIR)/_public/ $(O_DIR)/
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
	$(O_DIR)/libft/ft_base/ft_bitset.o $(O_DIR)/libft/ft_base/ft_bzero.o \
	$(O_DIR)/libft/ft_base/ft_clock.o $(O_DIR)/libft/ft_base/ft_clock_stack.o \
	$(O_DIR)/libft/ft_base/ft_emalloc.o $(O_DIR)/libft/ft_base/ft_escape.o \
	$(O_DIR)/libft/ft_base/ft_getenv.o $(O_DIR)/libft/ft_base/ft_is.o \
	$(O_DIR)/libft/ft_base/ft_max.o $(O_DIR)/libft/ft_base/ft_memcmp.o \
	$(O_DIR)/libft/ft_base/ft_memcpy.o $(O_DIR)/libft/ft_base/ft_memdup.o \
	$(O_DIR)/libft/ft_base/ft_memfill.o $(O_DIR)/libft/ft_base/ft_memmove.o \
	$(O_DIR)/libft/ft_base/ft_memrcpy.o $(O_DIR)/libft/ft_base/ft_memset.o \
	$(O_DIR)/libft/ft_base/ft_memstart.o $(O_DIR)/libft/ft_base/ft_memswap.o \
	$(O_DIR)/libft/ft_base/ft_min.o $(O_DIR)/libft/ft_base/ft_nanoclock.o \
	$(O_DIR)/libft/ft_base/ft_rand.o $(O_DIR)/libft/ft_base/ft_randbool.o \
	$(O_DIR)/libft/ft_base/ft_strchri.o $(O_DIR)/libft/ft_base/ft_strlen.o \
	$(O_DIR)/libft/ft_base/ft_sub.o $(O_DIR)/libft/ft_base/ft_subfind.o \
	$(O_DIR)/libft/ft_base/ft_subnext.o $(O_DIR)/libft/ft_base/ft_subto.o \
	$(O_DIR)/libft/ft_base/ft_unescape.o $(O_DIR)/libft/ft_base/ft_widetoa.o \
	$(O_DIR)/libft/ft_base/ft_wstrconv.o $(O_DIR)/libft/ft_base/ft_wstrlen.o \
	$(O_DIR)/libft/ft_base/ft_wstrnconv.o $(O_DIR)/libft/ft_dstr/ft_dstradd.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrclear.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrextend.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrspan.o \
	$(O_DIR)/libft/get_next_line/get_next_line.o \
	$(O_DIR)/libft/ft_hmap/ft_djb2.o $(O_DIR)/libft/ft_hmap/ft_hmapdatas.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapdestroy.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapget.o $(O_DIR)/libft/ft_hmap/ft_hmapkeys.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapnew.o $(O_DIR)/libft/ft_hmap/ft_hmapput.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapputp.o $(O_DIR)/libft/ft_hmap/ft_hmaprem.o \
	$(O_DIR)/libft/ft_hmap/hmap_puth.o \
	$(O_DIR)/srcs/ft_image_loader/ft_load_image.o \
	$(O_DIR)/srcs/ft_image_loader/tga_loader.o $(O_DIR)/libft/ft_in/file_in.o \
	$(O_DIR)/libft/ft_in/file_in_open.o $(O_DIR)/libft/ft_in/ft_in_refresh.o \
	$(O_DIR)/libft/ft_in/ft_read.o $(O_DIR)/libft/ft_in/ft_readto.o \
	$(O_DIR)/libft/ft_list/ft_listadd.o $(O_DIR)/libft/ft_list/ft_listremove.o \
	$(O_DIR)/libft/ft_list/ft_listsort.o \
	$(O_DIR)/libft/ft_math/ft_mat4look_at.o \
	$(O_DIR)/libft/ft_math/ft_mat4mult.o \
	$(O_DIR)/libft/ft_math/ft_mat4perspective.o \
	$(O_DIR)/libft/ft_math/ft_mat4reflect.o \
	$(O_DIR)/libft/ft_math/ft_mat4rotate.o \
	$(O_DIR)/libft/ft_math/ft_mat4scale.o \
	$(O_DIR)/libft/ft_math/ft_mat4shear.o \
	$(O_DIR)/libft/ft_math/ft_mat4translate.o \
	$(O_DIR)/libft/ft_math/ft_mat4transpose.o \
	$(O_DIR)/libft/ft_math/ft_vec3cross.o $(O_DIR)/libft/ft_math/ft_vec3dot.o \
	$(O_DIR)/libft/ft_math/ft_vec3front.o $(O_DIR)/libft/ft_math/ft_vec3norm.o \
	$(O_DIR)/libft/ft_math/ft_vec3rotate.o $(O_DIR)/libft/ft_math/ft_vec3sub.o \
	$(O_DIR)/libft/ft_out/ft_putchar.o $(O_DIR)/libft/ft_out/ft_putendl.o \
	$(O_DIR)/libft/ft_out/ft_putfloat.o $(O_DIR)/libft/ft_out/ft_putint.o \
	$(O_DIR)/libft/ft_out/ft_putnchar.o $(O_DIR)/libft/ft_out/ft_putpad.o \
	$(O_DIR)/libft/ft_out/ft_putstr.o $(O_DIR)/libft/ft_out/ft_putsub.o \
	$(O_DIR)/libft/ft_out/ft_putuint.o $(O_DIR)/libft/ft_out/ft_str_out.o \
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
	$(O_DIR)/libft/ft_printf/ft_vprintf.o $(O_DIR)/libft/ft_vector/ft_vclear.o \
	$(O_DIR)/libft/ft_vector/ft_vpush.o $(O_DIR)/libft/ft_vector/ft_vremove.o \
	$(O_DIR)/libft/ft_vector/ft_vreserve.o $(O_DIR)/srcs/main/callbacks.o \
	$(O_DIR)/srcs/main/init_window.o $(O_DIR)/srcs/main/main.o \
	$(O_DIR)/srcs/main/motions.o $(O_DIR)/srcs/mesh_loader/build_mesh.o \
	$(O_DIR)/srcs/mesh_loader/build_mtl.o \
	$(O_DIR)/srcs/mesh_loader/load_mesh.o \
	$(O_DIR)/srcs/mesh_loader/parse_mesh.o \
	$(O_DIR)/srcs/mesh_loader/parse_mesh_tokens.o \
	$(O_DIR)/srcs/mesh_loader/parse_mesh_tokens_mtl.o \
	$(O_DIR)/srcs/mesh_loader/send_mesh.o $(O_DIR)/srcs/mtl_loader/load_mtl.o \
	$(O_DIR)/srcs/mtl_loader/parse_mtl.o \
	$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens.o \
	$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens_map.o \
	$(O_DIR)/srcs/obj/ft_obj_matrix.o $(O_DIR)/srcs/obj/ft_obj_rotate.o \
	$(O_DIR)/srcs/obj/ft_obj_scale.o $(O_DIR)/srcs/obj/ft_obj_shear.o \
	$(O_DIR)/srcs/obj/ft_obj_translate.o $(O_DIR)/srcs/obj_anim/anim_c_move.o \
	$(O_DIR)/srcs/obj_anim/anim_c_rot.o $(O_DIR)/srcs/obj_anim/anim_c_scale.o \
	$(O_DIR)/srcs/obj_anim/anim_c_shear.o $(O_DIR)/srcs/render/simple_render.o \
	$(O_DIR)/srcs/shader_loader/compile_shader.o \
	$(O_DIR)/srcs/shader_loader/load_shader.o \
	$(O_DIR)/srcs/shader_loader/load_uniforms.o \
	$(O_DIR)/srcs/shader_loader/read_shader.o \
	$(O_DIR)/srcs/shader_loader/shader_get_uniform.o \
	$(O_DIR)/srcs/texture_loader/load_texture.o $(O_DIR)/srcs/utils/fps.o \
	$(O_DIR)/srcs/utils/ft_error.o $(O_DIR)/srcs/utils/ft_listremove_next.o \
	$(O_DIR)/srcs/utils/ft_subends.o $(O_DIR)/srcs/utils/ft_substart.o \
	$(O_DIR)/srcs/utils/parse_fvec.o
PUBLIC_LINKS += $(O_DIR)/_public/anim.h $(O_DIR)/_public/camera.h \
	$(O_DIR)/_public/events.h $(O_DIR)/_public/ft/libft.h \
	$(O_DIR)/_public/ft/ft_colors.h $(O_DIR)/_public/ft/ft_wchar.h \
	$(O_DIR)/_public/ft/ft_dstr.h $(O_DIR)/_public/ft/get_next_line.h \
	$(O_DIR)/_public/ft/gl.h $(O_DIR)/_public/ft/ft_hmap.h \
	$(O_DIR)/_public/ft/ft_image_loader.h $(O_DIR)/_public/ft/ft_in.h \
	$(O_DIR)/_public/ft/ft_file_in.h $(O_DIR)/_public/ft/ft_list.h \
	$(O_DIR)/_public/ft/math.h $(O_DIR)/_public/ft/ft_out.h \
	$(O_DIR)/_public/ft/ft_str_out.h $(O_DIR)/_public/ft/ft_printf.h \
	$(O_DIR)/_public/ft/ft_vprintf.h $(O_DIR)/_public/ft/ft_vector.h \
	$(O_DIR)/_public/mesh.h $(O_DIR)/_public/mesh_loader.h \
	$(O_DIR)/_public/mtl.h $(O_DIR)/_public/mtl_loader.h \
	$(O_DIR)/_public/obj.h $(O_DIR)/_public/obj_anim.h \
	$(O_DIR)/_public/render.h $(O_DIR)/_public/shader.h \
	$(O_DIR)/_public/shader_loader.h $(O_DIR)/_public/texture.h \
	$(O_DIR)/_public/texture_loader.h $(O_DIR)/_public/utils.h

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
	libft/ft_math/public/math.h srcs/camera/include/camera.h
$(O_DIR)/srcs/camera/camera_look.o: srcs/camera/camera_look.c \
	libft/ft_math/public/math.h srcs/camera/include/camera.h
$(O_DIR)/srcs/camera/camera_move.o: srcs/camera/camera_move.c \
	libft/ft_math/public/math.h srcs/camera/include/camera.h

# module events
$(O_DIR)/srcs/events/events.o: srcs/events/events.c \
	libft/ft_base/public/libft.h libft/ft_gl/gl.h \
	libft/ft_list/public/ft_list.h srcs/events/include/events.h \
	srcs/utils/include/utils.h

# module ft::base
$(O_DIR)/libft/ft_base/ft_abs.o: libft/ft_base/ft_abs.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_assert.o: libft/ft_base/ft_assert.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_atoib.o: libft/ft_base/ft_atoib.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_bitset.o: libft/ft_base/ft_bitset.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_bzero.o: libft/ft_base/ft_bzero.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_clock.o: libft/ft_base/ft_clock.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_clock_stack.o: libft/ft_base/ft_clock_stack.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_emalloc.o: libft/ft_base/ft_emalloc.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_escape.o: libft/ft_base/ft_escape.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_getenv.o: libft/ft_base/ft_getenv.c \
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
$(O_DIR)/libft/ft_base/ft_subfind.o: libft/ft_base/ft_subfind.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_subnext.o: libft/ft_base/ft_subnext.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_subto.o: libft/ft_base/ft_subto.c \
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

# module ft::dstr
$(O_DIR)/libft/ft_dstr/ft_dstradd.o: libft/ft_dstr/ft_dstradd.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h
$(O_DIR)/libft/ft_dstr/ft_dstrclear.o: libft/ft_dstr/ft_dstrclear.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h
$(O_DIR)/libft/ft_dstr/ft_dstrextend.o: libft/ft_dstr/ft_dstrextend.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h
$(O_DIR)/libft/ft_dstr/ft_dstrspan.o: libft/ft_dstr/ft_dstrspan.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h

# module ft::get_next_line
$(O_DIR)/libft/get_next_line/get_next_line.o: \
	libft/get_next_line/get_next_line.c libft/ft_base/public/libft.h \
	libft/get_next_line/gnl_internal.h \
	libft/get_next_line/public/get_next_line.h

$(O_DIR)/libft/get_next_line/get_next_line.o: INCLUDE_FLAGS += \
	-Ilibft/get_next_line

# module ft::gl
ifeq ($(shell uname),Darwin)
  BASE_FLAGS += -DMAC_OS_MODE=1
  LINK_FLAGS += -lglfw3 -framework OpenGL
else
  LINK_FLAGS += -lglfw -lGL -lGLEW
endif

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

# module ft::image_loader
$(O_DIR)/srcs/ft_image_loader/ft_load_image.o: \
	srcs/ft_image_loader/ft_load_image.c libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_in/public/ft_file_in.h \
	libft/ft_in/public/ft_in.h srcs/ft_image_loader/image_loader.h \
	srcs/ft_image_loader/public/ft_image_loader.h
$(O_DIR)/srcs/ft_image_loader/tga_loader.o: srcs/ft_image_loader/tga_loader.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_in.h srcs/ft_image_loader/image_loader.h \
	srcs/ft_image_loader/public/ft_image_loader.h

$(O_DIR)/srcs/ft_image_loader/ft_load_image.o \
$(O_DIR)/srcs/ft_image_loader/tga_loader.o: INCLUDE_FLAGS += \
	-Isrcs/ft_image_loader

# module ft::in
$(O_DIR)/libft/ft_in/file_in.o: libft/ft_in/file_in.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_file_in.h libft/ft_in/public/ft_in.h
$(O_DIR)/libft/ft_in/file_in_open.o: libft/ft_in/file_in_open.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_file_in.h libft/ft_in/public/ft_in.h
$(O_DIR)/libft/ft_in/ft_in_refresh.o: libft/ft_in/ft_in_refresh.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_in.h
$(O_DIR)/libft/ft_in/ft_read.o: libft/ft_in/ft_read.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_in.h
$(O_DIR)/libft/ft_in/ft_readto.o: libft/ft_in/ft_readto.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_in.h

# module ft::list
$(O_DIR)/libft/ft_list/ft_listadd.o: libft/ft_list/ft_listadd.c \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h
$(O_DIR)/libft/ft_list/ft_listremove.o: libft/ft_list/ft_listremove.c \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h
$(O_DIR)/libft/ft_list/ft_listsort.o: libft/ft_list/ft_listsort.c \
	libft/ft_base/public/libft.h libft/ft_list/public/ft_list.h

# module ft::math
$(O_DIR)/libft/ft_math/ft_mat4look_at.o: libft/ft_math/ft_mat4look_at.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_mat4mult.o: libft/ft_math/ft_mat4mult.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_mat4perspective.o: \
	libft/ft_math/ft_mat4perspective.c libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_mat4reflect.o: libft/ft_math/ft_mat4reflect.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_mat4rotate.o: libft/ft_math/ft_mat4rotate.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_mat4scale.o: libft/ft_math/ft_mat4scale.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_mat4shear.o: libft/ft_math/ft_mat4shear.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_mat4translate.o: libft/ft_math/ft_mat4translate.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_mat4transpose.o: libft/ft_math/ft_mat4transpose.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_vec3cross.o: libft/ft_math/ft_vec3cross.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_vec3dot.o: libft/ft_math/ft_vec3dot.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_vec3front.o: libft/ft_math/ft_vec3front.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_vec3norm.o: libft/ft_math/ft_vec3norm.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_vec3rotate.o: libft/ft_math/ft_vec3rotate.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_vec3sub.o: libft/ft_math/ft_vec3sub.c \
	libft/ft_math/public/math.h

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
$(O_DIR)/libft/ft_out/ft_str_out.o: libft/ft_out/ft_str_out.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_out/public/ft_str_out.h
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
$(O_DIR)/libft/ft_out/ft_putuint.o $(O_DIR)/libft/ft_out/ft_str_out.o \
$(O_DIR)/libft/ft_out/ft_write.o $(O_DIR)/libft/ft_out/ft_write_char.o \
$(O_DIR)/libft/ft_out/ft_write_nchar.o $(O_DIR)/libft/ft_out/out_formats.o: \
	INCLUDE_FLAGS += -Ilibft/ft_out

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
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_out/public/ft_str_out.h libft/ft_printf/printf_internal.h \
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

# module ft::vector
$(O_DIR)/libft/ft_vector/ft_vclear.o: libft/ft_vector/ft_vclear.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h
$(O_DIR)/libft/ft_vector/ft_vpush.o: libft/ft_vector/ft_vpush.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h
$(O_DIR)/libft/ft_vector/ft_vremove.o: libft/ft_vector/ft_vremove.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h
$(O_DIR)/libft/ft_vector/ft_vreserve.o: libft/ft_vector/ft_vreserve.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h

# module main
$(O_DIR)/srcs/main/callbacks.o: srcs/main/callbacks.c \
	libft/ft_base/public/libft.h libft/ft_gl/gl.h libft/ft_math/public/math.h \
	libft/ft_vector/public/ft_vector.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/events/include/events.h \
	srcs/main/include/main.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/render/public/render.h srcs/texture/texture.h
$(O_DIR)/srcs/main/init_window.o: srcs/main/init_window.c \
	libft/ft_base/public/libft.h libft/ft_gl/gl.h \
	libft/ft_list/public/ft_list.h libft/ft_math/public/math.h \
	libft/ft_vector/public/ft_vector.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/main/include/main.h srcs/mesh/mesh.h \
	srcs/mtl/mtl.h srcs/obj/include/obj.h srcs/render/public/render.h \
	srcs/texture/texture.h srcs/utils/include/utils.h
$(O_DIR)/srcs/main/main.o: srcs/main/main.c libft/ft_base/public/libft.h \
	libft/ft_gl/gl.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_list/public/ft_list.h libft/ft_math/public/math.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/public/ft_printf.h \
	libft/ft_vector/public/ft_vector.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/events/include/events.h \
	srcs/main/include/main.h srcs/mesh/mesh.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/obj_anim/include/obj_anim.h \
	srcs/render/public/render.h srcs/shader/shader.h srcs/texture/texture.h \
	srcs/utils/include/utils.h
$(O_DIR)/srcs/main/motions.o: srcs/main/motions.c libft/ft_base/public/libft.h \
	libft/ft_gl/gl.h libft/ft_math/public/math.h \
	libft/ft_vector/public/ft_vector.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/main/include/main.h \
	srcs/main/include/motions.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/render/public/render.h srcs/texture/texture.h

$(O_DIR)/srcs/main/callbacks.o $(O_DIR)/srcs/main/init_window.o \
$(O_DIR)/srcs/main/main.o $(O_DIR)/srcs/main/motions.o: MDR += lol
$(O_DIR)/srcs/main/callbacks.o $(O_DIR)/srcs/main/init_window.o \
$(O_DIR)/srcs/main/main.o $(O_DIR)/srcs/main/motions.o: INCLUDE_FLAGS += \
	-Isrcs/main/include

# module mesh

# module mesh_loader
$(O_DIR)/srcs/mesh_loader/build_mesh.o: srcs/mesh_loader/build_mesh.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_list/public/ft_list.h libft/ft_math/public/math.h \
	libft/ft_vector/public/ft_vector.h srcs/mesh/mesh.h \
	srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h srcs/utils/include/utils.h
$(O_DIR)/srcs/mesh_loader/build_mtl.o: srcs/mesh_loader/build_mtl.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_math/public/math.h libft/ft_vector/public/ft_vector.h \
	srcs/mesh/mesh.h srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h
$(O_DIR)/srcs/mesh_loader/load_mesh.o: srcs/mesh_loader/load_mesh.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_math/public/math.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h libft/ft_vector/public/ft_vector.h \
	srcs/mesh/mesh.h srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h
$(O_DIR)/srcs/mesh_loader/parse_mesh.o: srcs/mesh_loader/parse_mesh.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_list/public/ft_list.h libft/ft_math/public/math.h \
	libft/ft_vector/public/ft_vector.h \
	libft/get_next_line/public/get_next_line.h srcs/mesh/mesh.h \
	srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h srcs/utils/include/utils.h
$(O_DIR)/srcs/mesh_loader/parse_mesh_tokens.o: \
	srcs/mesh_loader/parse_mesh_tokens.c libft/ft_base/public/libft.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_list/public/ft_list.h \
	libft/ft_math/public/math.h libft/ft_vector/public/ft_vector.h \
	srcs/mesh/mesh.h srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h srcs/utils/include/utils.h
$(O_DIR)/srcs/mesh_loader/parse_mesh_tokens_mtl.o: \
	srcs/mesh_loader/parse_mesh_tokens_mtl.c libft/ft_base/public/libft.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_list/public/ft_list.h \
	libft/ft_math/public/math.h libft/ft_vector/public/ft_vector.h \
	srcs/mesh/mesh.h srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/mtl_loader/include/public/mtl_loader.h srcs/texture/texture.h \
	srcs/utils/include/utils.h
$(O_DIR)/srcs/mesh_loader/send_mesh.o: srcs/mesh_loader/send_mesh.c \
	libft/ft_base/public/libft.h libft/ft_gl/gl.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_math/public/math.h \
	libft/ft_vector/public/ft_vector.h srcs/mesh/mesh.h \
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
	libft/ft_list/public/ft_list.h libft/ft_math/public/math.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/public/ft_printf.h \
	srcs/mtl/mtl.h srcs/mtl_loader/include/internal.h \
	srcs/mtl_loader/include/public/mtl_loader.h srcs/texture/texture.h \
	srcs/utils/include/utils.h
$(O_DIR)/srcs/mtl_loader/parse_mtl.o: srcs/mtl_loader/parse_mtl.c \
	libft/ft_base/public/libft.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_list/public/ft_list.h libft/ft_math/public/math.h \
	libft/get_next_line/public/get_next_line.h srcs/mtl/mtl.h \
	srcs/mtl_loader/include/internal.h \
	srcs/mtl_loader/include/public/mtl_loader.h srcs/texture/texture.h \
	srcs/utils/include/utils.h
$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens.o: \
	srcs/mtl_loader/parse_mtl_tokens.c libft/ft_base/public/libft.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_list/public/ft_list.h \
	libft/ft_math/public/math.h srcs/mtl/mtl.h \
	srcs/mtl_loader/include/internal.h \
	srcs/mtl_loader/include/public/mtl_loader.h srcs/texture/texture.h \
	srcs/utils/include/utils.h
$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens_map.o: \
	srcs/mtl_loader/parse_mtl_tokens_map.c libft/ft_base/public/libft.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_math/public/math.h srcs/mtl/mtl.h \
	srcs/mtl_loader/include/internal.h \
	srcs/mtl_loader/include/public/mtl_loader.h srcs/texture/texture.h \
	srcs/texture_loader/public/texture_loader.h

$(O_DIR)/srcs/mtl_loader/load_mtl.o $(O_DIR)/srcs/mtl_loader/parse_mtl.o \
$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens.o \
$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens_map.o: INCLUDE_FLAGS += \
	-Isrcs/mtl_loader/include

# module obj
$(O_DIR)/srcs/obj/ft_obj_matrix.o: srcs/obj/ft_obj_matrix.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math.h \
	libft/ft_vector/public/ft_vector.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/texture/texture.h
$(O_DIR)/srcs/obj/ft_obj_rotate.o: srcs/obj/ft_obj_rotate.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math.h \
	libft/ft_vector/public/ft_vector.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/texture/texture.h
$(O_DIR)/srcs/obj/ft_obj_scale.o: srcs/obj/ft_obj_scale.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math.h \
	libft/ft_vector/public/ft_vector.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/texture/texture.h
$(O_DIR)/srcs/obj/ft_obj_shear.o: srcs/obj/ft_obj_shear.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math.h \
	libft/ft_vector/public/ft_vector.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/texture/texture.h
$(O_DIR)/srcs/obj/ft_obj_translate.o: srcs/obj/ft_obj_translate.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math.h \
	libft/ft_vector/public/ft_vector.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/texture/texture.h

# module obj_anim
$(O_DIR)/srcs/obj_anim/anim_c_move.o: srcs/obj_anim/anim_c_move.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math.h \
	libft/ft_vector/public/ft_vector.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/obj_anim/include/obj_anim.h \
	srcs/texture/texture.h
$(O_DIR)/srcs/obj_anim/anim_c_rot.o: srcs/obj_anim/anim_c_rot.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math.h \
	libft/ft_vector/public/ft_vector.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/obj_anim/include/obj_anim.h \
	srcs/texture/texture.h
$(O_DIR)/srcs/obj_anim/anim_c_scale.o: srcs/obj_anim/anim_c_scale.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math.h \
	libft/ft_vector/public/ft_vector.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/obj_anim/include/obj_anim.h \
	srcs/texture/texture.h
$(O_DIR)/srcs/obj_anim/anim_c_shear.o: srcs/obj_anim/anim_c_shear.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math.h \
	libft/ft_vector/public/ft_vector.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/obj_anim/include/obj_anim.h \
	srcs/texture/texture.h

# module render
$(O_DIR)/srcs/render/simple_render.o: srcs/render/simple_render.c \
	libft/ft_base/public/libft.h libft/ft_gl/gl.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_list/public/ft_list.h \
	libft/ft_math/public/math.h srcs/camera/include/camera.h srcs/mesh/mesh.h \
	srcs/mtl/mtl.h srcs/render/public/render.h srcs/shader/shader.h \
	srcs/shader_loader/include/public/shader_loader.h srcs/texture/texture.h \
	srcs/utils/include/utils.h

# module shader

# module shader_loader
$(O_DIR)/srcs/shader_loader/compile_shader.o: \
	srcs/shader_loader/compile_shader.c libft/ft_base/public/ft_colors.h \
	libft/ft_base/public/libft.h libft/ft_gl/gl.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_list/public/ft_list.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/public/ft_printf.h \
	srcs/shader/shader.h srcs/shader_loader/include/internal.h \
	srcs/shader_loader/include/public/shader_loader.h
$(O_DIR)/srcs/shader_loader/load_shader.o: srcs/shader_loader/load_shader.c \
	libft/ft_base/public/libft.h libft/ft_gl/gl.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_list/public/ft_list.h \
	srcs/shader/shader.h srcs/shader_loader/include/internal.h \
	srcs/shader_loader/include/public/shader_loader.h \
	srcs/utils/include/utils.h
$(O_DIR)/srcs/shader_loader/load_uniforms.o: \
	srcs/shader_loader/load_uniforms.c libft/ft_base/public/libft.h \
	libft/ft_gl/gl.h libft/ft_hmap/public/ft_hmap.h \
	libft/ft_list/public/ft_list.h srcs/shader/shader.h \
	srcs/shader_loader/include/internal.h \
	srcs/shader_loader/include/public/shader_loader.h \
	srcs/utils/include/utils.h
$(O_DIR)/srcs/shader_loader/read_shader.o: srcs/shader_loader/read_shader.c \
	libft/ft_base/public/libft.h libft/ft_gl/gl.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_list/public/ft_list.h \
	libft/get_next_line/public/get_next_line.h srcs/shader/shader.h \
	srcs/shader_loader/include/internal.h \
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
$(O_DIR)/srcs/texture_loader/load_texture.o: \
	srcs/texture_loader/load_texture.c libft/ft_base/public/libft.h \
	libft/ft_gl/gl.h libft/ft_hmap/public/ft_hmap.h \
	srcs/ft_image_loader/public/ft_image_loader.h srcs/texture/texture.h \
	srcs/texture_loader/public/texture_loader.h

$(O_DIR)/srcs/texture_loader/load_texture.o: INCLUDE_FLAGS += \
	-Isrcs/texture_loader/include

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
	srcs/utils/include/utils.h

# public links
$(O_DIR)/_public/anim.h: srcs/anim/include/anim.h
$(O_DIR)/_public/camera.h: srcs/camera/include/camera.h
$(O_DIR)/_public/events.h: srcs/events/include/events.h
$(O_DIR)/_public/ft/ft_colors.h: libft/ft_base/public/ft_colors.h
$(O_DIR)/_public/ft/ft_dstr.h: libft/ft_dstr/public/ft_dstr.h
$(O_DIR)/_public/ft/ft_file_in.h: libft/ft_in/public/ft_file_in.h
$(O_DIR)/_public/ft/ft_hmap.h: libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/_public/ft/ft_image_loader.h: \
srcs/ft_image_loader/public/ft_image_loader.h
$(O_DIR)/_public/ft/ft_in.h: libft/ft_in/public/ft_in.h
$(O_DIR)/_public/ft/ft_list.h: libft/ft_list/public/ft_list.h
$(O_DIR)/_public/ft/ft_out.h: libft/ft_out/public/ft_out.h
$(O_DIR)/_public/ft/ft_printf.h: libft/ft_printf/public/ft_printf.h
$(O_DIR)/_public/ft/ft_str_out.h: libft/ft_out/public/ft_str_out.h
$(O_DIR)/_public/ft/ft_vector.h: libft/ft_vector/public/ft_vector.h
$(O_DIR)/_public/ft/ft_vprintf.h: libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/_public/ft/ft_wchar.h: libft/ft_base/public/ft_wchar.h
$(O_DIR)/_public/ft/get_next_line.h: \
libft/get_next_line/public/get_next_line.h
$(O_DIR)/_public/ft/gl.h: libft/ft_gl/gl.h
$(O_DIR)/_public/ft/libft.h: libft/ft_base/public/libft.h
$(O_DIR)/_public/ft/math.h: libft/ft_math/public/math.h
$(O_DIR)/_public/mesh.h: srcs/mesh/mesh.h
$(O_DIR)/_public/mesh_loader.h: srcs/mesh_loader/include/public/mesh_loader.h
$(O_DIR)/_public/mtl.h: srcs/mtl/mtl.h
$(O_DIR)/_public/mtl_loader.h: srcs/mtl_loader/include/public/mtl_loader.h
$(O_DIR)/_public/obj.h: srcs/obj/include/obj.h
$(O_DIR)/_public/obj_anim.h: srcs/obj_anim/include/obj_anim.h
$(O_DIR)/_public/render.h: srcs/render/public/render.h
$(O_DIR)/_public/shader.h: srcs/shader/shader.h
$(O_DIR)/_public/shader_loader.h: \
srcs/shader_loader/include/public/shader_loader.h
$(O_DIR)/_public/texture.h: srcs/texture/texture.h
$(O_DIR)/_public/texture_loader.h: srcs/texture_loader/public/texture_loader.h
$(O_DIR)/_public/utils.h: srcs/utils/include/utils.h
