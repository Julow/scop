O_FILES :=	o/srcs/anim/anim_start.o o/srcs/anim/anim_update.o \
			o/srcs/anim/smooth_back_in.o o/srcs/anim/smooth_back_in_out.o \
			o/srcs/anim/smooth_back_out.o o/srcs/anim/smooth_bounce.o \
			o/srcs/anim/smooth_elastic.o o/srcs/anim/smooth_in.o \
			o/srcs/anim/smooth_in_out.o o/srcs/anim/smooth_linear.o \
			o/srcs/anim/smooth_out.o o/srcs/camera/camera_get_view.o \
			o/srcs/camera/camera_look.o o/srcs/camera/camera_move.o \
			o/srcs/events/callbacks.o o/srcs/events/events.o \
			o/srcs/main/init_window.o o/srcs/main/main.o \
			o/srcs/math_utils/ft_mat4look_at.o o/srcs/math_utils/ft_mat4mult.o \
			o/srcs/math_utils/ft_mat4perspective.o \
			o/srcs/math_utils/ft_mat4reflect.o \
			o/srcs/math_utils/ft_mat4rotate.o o/srcs/math_utils/ft_mat4scale.o \
			o/srcs/math_utils/ft_mat4shear.o \
			o/srcs/math_utils/ft_mat4translate.o \
			o/srcs/math_utils/ft_mat4transpose.o \
			o/srcs/math_utils/ft_vec3cross.o o/srcs/math_utils/ft_vec3dot.o \
			o/srcs/math_utils/ft_vec3front.o o/srcs/math_utils/ft_vec3norm.o \
			o/srcs/math_utils/ft_vec3rotate.o o/srcs/math_utils/ft_vec3sub.o \
			o/srcs/mesh_loader/build_mesh.o o/srcs/mesh_loader/build_mtl.o \
			o/srcs/mesh_loader/load_mesh.o o/srcs/mesh_loader/parse_mesh.o \
			o/srcs/mesh_loader/parse_mesh_tokens.o \
			o/srcs/mesh_loader/parse_mesh_tokens_mtl.o \
			o/srcs/mesh_loader/send_mesh.o o/srcs/motions/motions.o \
			o/srcs/mtl_loader/load_mtl.o o/srcs/mtl_loader/parse_mtl.o \
			o/srcs/mtl_loader/parse_mtl_tokens.o \
			o/srcs/mtl_loader/parse_mtl_tokens_map.o \
			o/srcs/obj_anim/anim_c_move.o o/srcs/obj_anim/anim_c_rot.o \
			o/srcs/obj_anim/anim_c_scale.o o/srcs/obj_anim/anim_c_shear.o \
			o/srcs/renderer/simple_renderer.o \
			o/srcs/shader_loader/compile_shader.o \
			o/srcs/shader_loader/load_shader.o \
			o/srcs/shader_loader/load_uniforms.o \
			o/srcs/shader_loader/read_shader.o \
			o/srcs/shader_loader/shader_get_uniform.o \
			o/srcs/texture_loader/ft_loadimage.o \
			o/srcs/texture_loader/load_texture.o \
			o/srcs/texture_loader/tga_parser.o \
			o/srcs/transform/ft_transform_get.o \
			o/srcs/transform/ft_transform_move.o \
			o/srcs/transform/ft_transform_reflect.o \
			o/srcs/transform/ft_transform_rotate.o \
			o/srcs/transform/ft_transform_scale.o \
			o/srcs/transform/ft_transform_shear.o o/srcs/utils/fps.o \
			o/srcs/utils/ft_error.o o/srcs/utils/ft_listremove_next.o \
			o/srcs/utils/ft_subends.o o/srcs/utils/ft_substart.o \
			o/srcs/utils/parse_fvec.o

LIBS_DEPEND := libft/libft.a

libs:
	make -C libft
.PHONY: libs



MAX_SOURCE_LEN := 40
o/srcs/anim/anim_start.o: srcs/anim/anim_start.c | o/srcs/anim/
o/srcs/anim/anim_update.o: srcs/anim/anim_update.c | o/srcs/anim/
o/srcs/anim/smooth_back_in.o: srcs/anim/smooth_back_in.c | o/srcs/anim/
o/srcs/anim/smooth_back_in_out.o: srcs/anim/smooth_back_in_out.c | o/srcs/anim/
o/srcs/anim/smooth_back_out.o: srcs/anim/smooth_back_out.c | o/srcs/anim/
o/srcs/anim/smooth_bounce.o: srcs/anim/smooth_bounce.c | o/srcs/anim/
o/srcs/anim/smooth_elastic.o: srcs/anim/smooth_elastic.c | o/srcs/anim/
o/srcs/anim/smooth_in.o: srcs/anim/smooth_in.c | o/srcs/anim/
o/srcs/anim/smooth_in_out.o: srcs/anim/smooth_in_out.c | o/srcs/anim/
o/srcs/anim/smooth_linear.o: srcs/anim/smooth_linear.c | o/srcs/anim/
o/srcs/anim/smooth_out.o: srcs/anim/smooth_out.c | o/srcs/anim/
o/srcs/camera/camera_get_view.o: srcs/camera/camera_get_view.c | o/srcs/camera/
o/srcs/camera/camera_look.o: srcs/camera/camera_look.c | o/srcs/camera/
o/srcs/camera/camera_move.o: srcs/camera/camera_move.c | o/srcs/camera/
o/srcs/events/callbacks.o: srcs/events/callbacks.c | o/srcs/events/
o/srcs/events/events.o: srcs/events/events.c | o/srcs/events/
o/srcs/main/init_window.o: srcs/main/init_window.c | o/srcs/main/
o/srcs/main/main.o: srcs/main/main.c | o/srcs/main/
o/srcs/math_utils/ft_mat4look_at.o: srcs/math_utils/ft_mat4look_at.c \
	| o/srcs/math_utils/
o/srcs/math_utils/ft_mat4mult.o: srcs/math_utils/ft_mat4mult.c \
	| o/srcs/math_utils/
o/srcs/math_utils/ft_mat4perspective.o: srcs/math_utils/ft_mat4perspective.c \
	| o/srcs/math_utils/
o/srcs/math_utils/ft_mat4reflect.o: srcs/math_utils/ft_mat4reflect.c \
	| o/srcs/math_utils/
o/srcs/math_utils/ft_mat4rotate.o: srcs/math_utils/ft_mat4rotate.c \
	| o/srcs/math_utils/
o/srcs/math_utils/ft_mat4scale.o: srcs/math_utils/ft_mat4scale.c \
	| o/srcs/math_utils/
o/srcs/math_utils/ft_mat4shear.o: srcs/math_utils/ft_mat4shear.c \
	| o/srcs/math_utils/
o/srcs/math_utils/ft_mat4translate.o: srcs/math_utils/ft_mat4translate.c \
	| o/srcs/math_utils/
o/srcs/math_utils/ft_mat4transpose.o: srcs/math_utils/ft_mat4transpose.c \
	| o/srcs/math_utils/
o/srcs/math_utils/ft_vec3cross.o: srcs/math_utils/ft_vec3cross.c \
	| o/srcs/math_utils/
o/srcs/math_utils/ft_vec3dot.o: srcs/math_utils/ft_vec3dot.c \
	| o/srcs/math_utils/
o/srcs/math_utils/ft_vec3front.o: srcs/math_utils/ft_vec3front.c \
	| o/srcs/math_utils/
o/srcs/math_utils/ft_vec3norm.o: srcs/math_utils/ft_vec3norm.c \
	| o/srcs/math_utils/
o/srcs/math_utils/ft_vec3rotate.o: srcs/math_utils/ft_vec3rotate.c \
	| o/srcs/math_utils/
o/srcs/math_utils/ft_vec3sub.o: srcs/math_utils/ft_vec3sub.c \
	| o/srcs/math_utils/
o/srcs/mesh_loader/build_mesh.o: srcs/mesh_loader/build_mesh.c \
	| o/srcs/mesh_loader/
o/srcs/mesh_loader/build_mtl.o: srcs/mesh_loader/build_mtl.c \
	| o/srcs/mesh_loader/
o/srcs/mesh_loader/load_mesh.o: srcs/mesh_loader/load_mesh.c \
	| o/srcs/mesh_loader/
o/srcs/mesh_loader/parse_mesh.o: srcs/mesh_loader/parse_mesh.c \
	| o/srcs/mesh_loader/
o/srcs/mesh_loader/parse_mesh_tokens.o: srcs/mesh_loader/parse_mesh_tokens.c \
	| o/srcs/mesh_loader/
o/srcs/mesh_loader/parse_mesh_tokens_mtl.o: \
	srcs/mesh_loader/parse_mesh_tokens_mtl.c | o/srcs/mesh_loader/
o/srcs/mesh_loader/send_mesh.o: srcs/mesh_loader/send_mesh.c \
	| o/srcs/mesh_loader/
o/srcs/motions/motions.o: srcs/motions/motions.c | o/srcs/motions/
o/srcs/mtl_loader/load_mtl.o: srcs/mtl_loader/load_mtl.c | o/srcs/mtl_loader/
o/srcs/mtl_loader/parse_mtl.o: srcs/mtl_loader/parse_mtl.c | o/srcs/mtl_loader/
o/srcs/mtl_loader/parse_mtl_tokens.o: srcs/mtl_loader/parse_mtl_tokens.c \
	| o/srcs/mtl_loader/
o/srcs/mtl_loader/parse_mtl_tokens_map.o: \
	srcs/mtl_loader/parse_mtl_tokens_map.c | o/srcs/mtl_loader/
o/srcs/obj_anim/anim_c_move.o: srcs/obj_anim/anim_c_move.c | o/srcs/obj_anim/
o/srcs/obj_anim/anim_c_rot.o: srcs/obj_anim/anim_c_rot.c | o/srcs/obj_anim/
o/srcs/obj_anim/anim_c_scale.o: srcs/obj_anim/anim_c_scale.c | o/srcs/obj_anim/
o/srcs/obj_anim/anim_c_shear.o: srcs/obj_anim/anim_c_shear.c | o/srcs/obj_anim/
o/srcs/renderer/simple_renderer.o: srcs/renderer/simple_renderer.c \
	| o/srcs/renderer/
o/srcs/shader_loader/compile_shader.o: srcs/shader_loader/compile_shader.c \
	| o/srcs/shader_loader/
o/srcs/shader_loader/load_shader.o: srcs/shader_loader/load_shader.c \
	| o/srcs/shader_loader/
o/srcs/shader_loader/load_uniforms.o: srcs/shader_loader/load_uniforms.c \
	| o/srcs/shader_loader/
o/srcs/shader_loader/read_shader.o: srcs/shader_loader/read_shader.c \
	| o/srcs/shader_loader/
o/srcs/shader_loader/shader_get_uniform.o: \
	srcs/shader_loader/shader_get_uniform.c | o/srcs/shader_loader/
o/srcs/texture_loader/ft_loadimage.o: srcs/texture_loader/ft_loadimage.c \
	| o/srcs/texture_loader/
o/srcs/texture_loader/load_texture.o: srcs/texture_loader/load_texture.c \
	| o/srcs/texture_loader/
o/srcs/texture_loader/tga_parser.o: srcs/texture_loader/tga_parser.c \
	| o/srcs/texture_loader/
o/srcs/transform/ft_transform_get.o: srcs/transform/ft_transform_get.c \
	| o/srcs/transform/
o/srcs/transform/ft_transform_move.o: srcs/transform/ft_transform_move.c \
	| o/srcs/transform/
o/srcs/transform/ft_transform_reflect.o: srcs/transform/ft_transform_reflect.c \
	| o/srcs/transform/
o/srcs/transform/ft_transform_rotate.o: srcs/transform/ft_transform_rotate.c \
	| o/srcs/transform/
o/srcs/transform/ft_transform_scale.o: srcs/transform/ft_transform_scale.c \
	| o/srcs/transform/
o/srcs/transform/ft_transform_shear.o: srcs/transform/ft_transform_shear.c \
	| o/srcs/transform/
o/srcs/utils/fps.o: srcs/utils/fps.c | o/srcs/utils/
o/srcs/utils/ft_error.o: srcs/utils/ft_error.c | o/srcs/utils/
o/srcs/utils/ft_listremove_next.o: srcs/utils/ft_listremove_next.c \
	| o/srcs/utils/
o/srcs/utils/ft_subends.o: srcs/utils/ft_subends.c | o/srcs/utils/
o/srcs/utils/ft_substart.o: srcs/utils/ft_substart.c | o/srcs/utils/
o/srcs/utils/parse_fvec.o: srcs/utils/parse_fvec.c | o/srcs/utils/
