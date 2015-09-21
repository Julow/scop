O_FILES :=	o/srcs/camera/camera_get_view.o o/srcs/camera/camera_look.o \
			o/srcs/camera/camera_move.o o/srcs/init_window.o \
			o/srcs/key_events.o o/srcs/main.o \
			o/srcs/math_utils/ft_mat4look_at.o o/srcs/math_utils/ft_mat4mult.o \
			o/srcs/math_utils/ft_mat4perspective.o \
			o/srcs/math_utils/ft_mat4rotate.o o/srcs/math_utils/ft_mat4scale.o \
			o/srcs/math_utils/ft_mat4translate.o \
			o/srcs/math_utils/ft_mat4transpose.o \
			o/srcs/math_utils/ft_vec3cross.o o/srcs/math_utils/ft_vec3dot.o \
			o/srcs/math_utils/ft_vec3front.o o/srcs/math_utils/ft_vec3norm.o \
			o/srcs/math_utils/ft_vec3rotate.o o/srcs/math_utils/ft_vec3sub.o \
			o/srcs/mesh_loader/build_mesh.o o/srcs/mesh_loader/build_mtl.o \
			o/srcs/mesh_loader/load_mesh.o o/srcs/mesh_loader/parse_mesh.o \
			o/srcs/mesh_loader/parse_mesh_tokens.o \
			o/srcs/mesh_loader/parse_mesh_tokens_mtl.o \
			o/srcs/mesh_loader/send_mesh.o o/srcs/motions.o \
			o/srcs/mouse_events.o o/srcs/mtl_loader/load_mtl.o \
			o/srcs/mtl_loader/parse_mtl.o o/srcs/mtl_loader/parse_mtl_tokens.o \
			o/srcs/mtl_loader/parse_mtl_tokens_map.o \
			o/srcs/obj/obj_get_model.o o/srcs/obj/obj_move.o \
			o/srcs/obj/obj_rotate.o o/srcs/obj/obj_scale.o \
			o/srcs/resources/get_res.o o/srcs/shader_loader/compile_shader.o \
			o/srcs/shader_loader/load_shader.o \
			o/srcs/shader_loader/read_shader.o o/srcs/simple_renderer.o \
			o/srcs/texture_loader/ft_loadimage.o \
			o/srcs/texture_loader/load_texture.o \
			o/srcs/texture_loader/tga_parser.o o/srcs/utils/fps.o \
			o/srcs/utils/ft_error.o o/srcs/utils/ft_listremove_next.o \
			o/srcs/utils/ft_substart.o o/srcs/utils/parse_fvec.o

LIBS_DEPEND := libft/libft.a

libs:
	make -C libft
.PHONY: libs

o/srcs/camera/camera_get_view.o: srcs/camera/camera_get_view.c \
	include/camera.h include/math_utils.h | o/srcs/camera/
o/srcs/camera/camera_look.o: srcs/camera/camera_look.c include/camera.h \
	include/math_utils.h | o/srcs/camera/
o/srcs/camera/camera_move.o: srcs/camera/camera_move.c include/camera.h \
	include/math_utils.h | o/srcs/camera/
o/srcs/init_window.o: srcs/init_window.c include/scop.h include/gl.h \
	include/camera.h include/math_utils.h include/shader_loader.h include/gl.h \
	include/mesh_loader.h include/mtl_loader.h include/texture_loader.h \
	include/math_utils.h include/math_utils.h include/texture_loader.h \
	include/utils.h | o/srcs/
o/srcs/key_events.o: srcs/key_events.c include/scop.h include/gl.h \
	include/camera.h include/math_utils.h include/shader_loader.h include/gl.h \
	include/mesh_loader.h include/mtl_loader.h include/texture_loader.h \
	include/math_utils.h include/math_utils.h include/texture_loader.h \
	include/utils.h include/gl.h | o/srcs/
o/srcs/main.o: srcs/main.c include/scop.h include/gl.h include/camera.h \
	include/math_utils.h include/shader_loader.h include/gl.h \
	include/mesh_loader.h include/mtl_loader.h include/texture_loader.h \
	include/math_utils.h include/math_utils.h include/texture_loader.h \
	include/shader_loader.h include/gl.h include/resources.h include/obj.h \
	include/math_utils.h include/mesh_loader.h include/mtl_loader.h \
	include/texture_loader.h include/math_utils.h include/math_utils.h \
	include/texture_loader.h include/shader_loader.h include/gl.h \
	include/math_utils.h include/utils.h | o/srcs/
o/srcs/math_utils/ft_mat4look_at.o: srcs/math_utils/ft_mat4look_at.c \
	include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_mat4mult.o: srcs/math_utils/ft_mat4mult.c \
	include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_mat4perspective.o: srcs/math_utils/ft_mat4perspective.c \
	include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_mat4rotate.o: srcs/math_utils/ft_mat4rotate.c \
	include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_mat4scale.o: srcs/math_utils/ft_mat4scale.c \
	include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_mat4translate.o: srcs/math_utils/ft_mat4translate.c \
	include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_mat4transpose.o: srcs/math_utils/ft_mat4transpose.c \
	include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_vec3cross.o: srcs/math_utils/ft_vec3cross.c \
	include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_vec3dot.o: srcs/math_utils/ft_vec3dot.c \
	include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_vec3front.o: srcs/math_utils/ft_vec3front.c \
	include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_vec3norm.o: srcs/math_utils/ft_vec3norm.c \
	include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_vec3rotate.o: srcs/math_utils/ft_vec3rotate.c \
	include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_vec3sub.o: srcs/math_utils/ft_vec3sub.c \
	include/math_utils.h | o/srcs/math_utils/
o/srcs/mesh_loader/build_mesh.o: srcs/mesh_loader/build_mesh.c \
	include/mesh_loader.h include/mtl_loader.h include/texture_loader.h \
	include/math_utils.h include/math_utils.h include/utils.h \
	| o/srcs/mesh_loader/
o/srcs/mesh_loader/build_mtl.o: srcs/mesh_loader/build_mtl.c \
	include/mesh_loader.h include/mtl_loader.h include/texture_loader.h \
	include/math_utils.h include/math_utils.h | o/srcs/mesh_loader/
o/srcs/mesh_loader/load_mesh.o: srcs/mesh_loader/load_mesh.c \
	include/mesh_loader.h include/mtl_loader.h include/texture_loader.h \
	include/math_utils.h include/math_utils.h | o/srcs/mesh_loader/
o/srcs/mesh_loader/parse_mesh.o: srcs/mesh_loader/parse_mesh.c \
	include/mesh_loader.h include/mtl_loader.h include/texture_loader.h \
	include/math_utils.h include/math_utils.h include/utils.h \
	| o/srcs/mesh_loader/
o/srcs/mesh_loader/parse_mesh_tokens.o: srcs/mesh_loader/parse_mesh_tokens.c \
	include/mesh_loader.h include/mtl_loader.h include/texture_loader.h \
	include/math_utils.h include/math_utils.h include/resources.h \
	include/utils.h | o/srcs/mesh_loader/
o/srcs/mesh_loader/parse_mesh_tokens_mtl.o: \
	srcs/mesh_loader/parse_mesh_tokens_mtl.c include/mesh_loader.h \
	include/mtl_loader.h include/texture_loader.h include/math_utils.h \
	include/math_utils.h include/resources.h include/utils.h \
	| o/srcs/mesh_loader/
o/srcs/mesh_loader/send_mesh.o: srcs/mesh_loader/send_mesh.c \
	include/mesh_loader.h include/mtl_loader.h include/texture_loader.h \
	include/math_utils.h include/math_utils.h include/gl.h | o/srcs/mesh_loader/
o/srcs/motions.o: srcs/motions.c include/scop.h include/gl.h include/camera.h \
	include/math_utils.h include/shader_loader.h include/gl.h \
	include/mesh_loader.h include/mtl_loader.h include/texture_loader.h \
	include/math_utils.h include/math_utils.h include/texture_loader.h \
	include/math_utils.h | o/srcs/
o/srcs/mouse_events.o: srcs/mouse_events.c include/gl.h include/scop.h \
	include/gl.h include/camera.h include/math_utils.h include/shader_loader.h \
	include/gl.h include/mesh_loader.h include/mtl_loader.h \
	include/texture_loader.h include/math_utils.h include/math_utils.h \
	include/texture_loader.h | o/srcs/
o/srcs/mtl_loader/load_mtl.o: srcs/mtl_loader/load_mtl.c include/mtl_loader.h \
	include/texture_loader.h include/math_utils.h include/utils.h \
	| o/srcs/mtl_loader/
o/srcs/mtl_loader/parse_mtl.o: srcs/mtl_loader/parse_mtl.c \
	include/mtl_loader.h include/texture_loader.h include/math_utils.h \
	include/utils.h | o/srcs/mtl_loader/
o/srcs/mtl_loader/parse_mtl_tokens.o: srcs/mtl_loader/parse_mtl_tokens.c \
	include/mtl_loader.h include/texture_loader.h include/math_utils.h \
	include/utils.h | o/srcs/mtl_loader/
o/srcs/mtl_loader/parse_mtl_tokens_map.o: \
	srcs/mtl_loader/parse_mtl_tokens_map.c include/mtl_loader.h \
	include/texture_loader.h include/math_utils.h include/resources.h \
	| o/srcs/mtl_loader/
o/srcs/obj/obj_get_model.o: srcs/obj/obj_get_model.c include/obj.h \
	include/math_utils.h include/mesh_loader.h include/mtl_loader.h \
	include/texture_loader.h include/math_utils.h include/math_utils.h \
	include/texture_loader.h include/shader_loader.h include/gl.h | o/srcs/obj/
o/srcs/obj/obj_move.o: srcs/obj/obj_move.c include/obj.h include/math_utils.h \
	include/mesh_loader.h include/mtl_loader.h include/texture_loader.h \
	include/math_utils.h include/math_utils.h include/texture_loader.h \
	include/shader_loader.h include/gl.h | o/srcs/obj/
o/srcs/obj/obj_rotate.o: srcs/obj/obj_rotate.c include/obj.h \
	include/math_utils.h include/mesh_loader.h include/mtl_loader.h \
	include/texture_loader.h include/math_utils.h include/math_utils.h \
	include/texture_loader.h include/shader_loader.h include/gl.h | o/srcs/obj/
o/srcs/obj/obj_scale.o: srcs/obj/obj_scale.c include/obj.h \
	include/math_utils.h include/mesh_loader.h include/mtl_loader.h \
	include/texture_loader.h include/math_utils.h include/math_utils.h \
	include/texture_loader.h include/shader_loader.h include/gl.h | o/srcs/obj/
o/srcs/resources/get_res.o: srcs/resources/get_res.c include/resources.h \
	include/shader_loader.h include/gl.h include/mesh_loader.h \
	include/mtl_loader.h include/texture_loader.h include/math_utils.h \
	include/math_utils.h include/mtl_loader.h include/texture_loader.h \
	include/math_utils.h include/texture_loader.h include/utils.h \
	| o/srcs/resources/
o/srcs/shader_loader/compile_shader.o: srcs/shader_loader/compile_shader.c \
	include/shader_loader.h include/gl.h | o/srcs/shader_loader/
o/srcs/shader_loader/load_shader.o: srcs/shader_loader/load_shader.c \
	include/shader_loader.h include/gl.h include/utils.h | o/srcs/shader_loader/
o/srcs/shader_loader/read_shader.o: srcs/shader_loader/read_shader.c \
	include/shader_loader.h include/gl.h include/utils.h | o/srcs/shader_loader/
o/srcs/simple_renderer.o: srcs/simple_renderer.c include/scop.h include/gl.h \
	include/camera.h include/math_utils.h include/shader_loader.h include/gl.h \
	include/mesh_loader.h include/mtl_loader.h include/texture_loader.h \
	include/math_utils.h include/math_utils.h include/texture_loader.h \
	include/camera.h include/math_utils.h | o/srcs/
o/srcs/texture_loader/ft_loadimage.o: srcs/texture_loader/ft_loadimage.c \
	include/texture_loader.h | o/srcs/texture_loader/
o/srcs/texture_loader/load_texture.o: srcs/texture_loader/load_texture.c \
	include/texture_loader.h include/scop.h include/gl.h include/camera.h \
	include/math_utils.h include/shader_loader.h include/gl.h \
	include/mesh_loader.h include/mtl_loader.h include/texture_loader.h \
	include/math_utils.h include/math_utils.h include/texture_loader.h \
	| o/srcs/texture_loader/
o/srcs/texture_loader/tga_parser.o: srcs/texture_loader/tga_parser.c \
	include/texture_loader.h include/utils.h | o/srcs/texture_loader/
o/srcs/utils/fps.o: srcs/utils/fps.c include/utils.h | o/srcs/utils/
o/srcs/utils/ft_error.o: srcs/utils/ft_error.c include/utils.h | o/srcs/utils/
o/srcs/utils/ft_listremove_next.o: srcs/utils/ft_listremove_next.c \
	include/utils.h | o/srcs/utils/
o/srcs/utils/ft_substart.o: srcs/utils/ft_substart.c include/utils.h \
	| o/srcs/utils/
o/srcs/utils/parse_fvec.o: srcs/utils/parse_fvec.c include/utils.h \
	| o/srcs/utils/
