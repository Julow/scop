O_FILES :=	o/srcs/anim/anim_start.o o/srcs/anim/anim_update.o \
			o/srcs/anim/smooth_back_in.o o/srcs/anim/smooth_back_in_out.o \
			o/srcs/anim/smooth_back_out.o o/srcs/anim/smooth_bounce.o \
			o/srcs/anim/smooth_elastic.o o/srcs/anim/smooth_in.o \
			o/srcs/anim/smooth_in_out.o o/srcs/anim/smooth_linear.o \
			o/srcs/anim/smooth_out.o o/srcs/camera/camera_get_view.o \
			o/srcs/camera/camera_look.o o/srcs/camera/camera_move.o \
			o/srcs/events/events.o o/srcs/main/callbacks.o \
			o/srcs/main/init_window.o o/srcs/main/main.o o/srcs/main/motions.o \
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
			o/srcs/mesh_loader/send_mesh.o o/srcs/mtl_loader/load_mtl.o \
			o/srcs/mtl_loader/parse_mtl.o o/srcs/mtl_loader/parse_mtl_tokens.o \
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
o/srcs/anim/anim_start.o: srcs/anim/anim_start.c srcs/anim/include/anim.h \
	| o/srcs/anim/
o/srcs/anim/anim_update.o: srcs/anim/anim_update.c srcs/anim/include/anim.h \
	| o/srcs/anim/
o/srcs/anim/smooth_back_in.o: srcs/anim/smooth_back_in.c \
	srcs/anim/include/anim.h | o/srcs/anim/
o/srcs/anim/smooth_back_in_out.o: srcs/anim/smooth_back_in_out.c \
	srcs/anim/include/anim.h | o/srcs/anim/
o/srcs/anim/smooth_back_out.o: srcs/anim/smooth_back_out.c \
	srcs/anim/include/anim.h | o/srcs/anim/
o/srcs/anim/smooth_bounce.o: srcs/anim/smooth_bounce.c \
	srcs/anim/include/anim.h | o/srcs/anim/
o/srcs/anim/smooth_elastic.o: srcs/anim/smooth_elastic.c \
	srcs/anim/include/anim.h | o/srcs/anim/
o/srcs/anim/smooth_in.o: srcs/anim/smooth_in.c srcs/anim/include/anim.h \
	| o/srcs/anim/
o/srcs/anim/smooth_in_out.o: srcs/anim/smooth_in_out.c \
	srcs/anim/include/anim.h | o/srcs/anim/
o/srcs/anim/smooth_linear.o: srcs/anim/smooth_linear.c \
	srcs/anim/include/anim.h | o/srcs/anim/
o/srcs/anim/smooth_out.o: srcs/anim/smooth_out.c srcs/anim/include/anim.h \
	| o/srcs/anim/
o/srcs/camera/camera_get_view.o: srcs/camera/camera_get_view.c \
	srcs/camera/include/camera.h srcs/math_utils/include/math_utils.h \
	| o/srcs/camera/
o/srcs/camera/camera_look.o: srcs/camera/camera_look.c \
	srcs/camera/include/camera.h srcs/math_utils/include/math_utils.h \
	| o/srcs/camera/
o/srcs/camera/camera_move.o: srcs/camera/camera_move.c \
	srcs/camera/include/camera.h srcs/math_utils/include/math_utils.h \
	| o/srcs/camera/
o/srcs/events/events.o: srcs/events/events.c srcs/events/include/events.h \
	srcs/utils/include/utils.h | o/srcs/events/
o/srcs/main/callbacks.o: srcs/main/callbacks.c srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/main/include/main.h \
	srcs/math_utils/include/math_utils.h \
	srcs/mesh_loader/include/mesh_loader.h \
	srcs/mtl_loader/include/mtl_loader.h srcs/obj/include/obj.h \
	srcs/renderer/include/renderer.h \
	srcs/texture_loader/include/texture_loader.h \
	srcs/transform/include/transform.h srcs/events/include/events.h \
	| o/srcs/main/
o/srcs/main/init_window.o: srcs/main/init_window.c srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/main/include/main.h \
	srcs/math_utils/include/math_utils.h \
	srcs/mesh_loader/include/mesh_loader.h \
	srcs/mtl_loader/include/mtl_loader.h srcs/obj/include/obj.h \
	srcs/renderer/include/renderer.h \
	srcs/texture_loader/include/texture_loader.h \
	srcs/transform/include/transform.h srcs/utils/include/utils.h | o/srcs/main/
o/srcs/main/main.o: srcs/main/main.c srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/main/include/main.h \
	srcs/math_utils/include/math_utils.h \
	srcs/mesh_loader/include/mesh_loader.h \
	srcs/mtl_loader/include/mtl_loader.h srcs/obj/include/obj.h \
	srcs/renderer/include/renderer.h \
	srcs/texture_loader/include/texture_loader.h \
	srcs/transform/include/transform.h \
	srcs/shader_loader/include/shader_loader.h \
	srcs/obj_anim/include/obj_anim.h srcs/events/include/events.h \
	srcs/utils/include/utils.h | o/srcs/main/
o/srcs/main/motions.o: srcs/main/motions.c srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/main/include/main.h \
	srcs/math_utils/include/math_utils.h \
	srcs/mesh_loader/include/mesh_loader.h \
	srcs/mtl_loader/include/mtl_loader.h srcs/obj/include/obj.h \
	srcs/renderer/include/renderer.h \
	srcs/texture_loader/include/texture_loader.h \
	srcs/transform/include/transform.h srcs/main/include/motions.h \
	| o/srcs/main/
o/srcs/math_utils/ft_mat4look_at.o: srcs/math_utils/ft_mat4look_at.c \
	srcs/math_utils/include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_mat4mult.o: srcs/math_utils/ft_mat4mult.c \
	srcs/math_utils/include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_mat4perspective.o: srcs/math_utils/ft_mat4perspective.c \
	srcs/math_utils/include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_mat4reflect.o: srcs/math_utils/ft_mat4reflect.c \
	srcs/math_utils/include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_mat4rotate.o: srcs/math_utils/ft_mat4rotate.c \
	srcs/math_utils/include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_mat4scale.o: srcs/math_utils/ft_mat4scale.c \
	srcs/math_utils/include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_mat4shear.o: srcs/math_utils/ft_mat4shear.c \
	srcs/math_utils/include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_mat4translate.o: srcs/math_utils/ft_mat4translate.c \
	srcs/math_utils/include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_mat4transpose.o: srcs/math_utils/ft_mat4transpose.c \
	srcs/math_utils/include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_vec3cross.o: srcs/math_utils/ft_vec3cross.c \
	srcs/math_utils/include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_vec3dot.o: srcs/math_utils/ft_vec3dot.c \
	srcs/math_utils/include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_vec3front.o: srcs/math_utils/ft_vec3front.c \
	srcs/math_utils/include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_vec3norm.o: srcs/math_utils/ft_vec3norm.c \
	srcs/math_utils/include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_vec3rotate.o: srcs/math_utils/ft_vec3rotate.c \
	srcs/math_utils/include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_vec3sub.o: srcs/math_utils/ft_vec3sub.c \
	srcs/math_utils/include/math_utils.h | o/srcs/math_utils/
o/srcs/mesh_loader/build_mesh.o: srcs/mesh_loader/build_mesh.c \
	srcs/math_utils/include/math_utils.h \
	srcs/mesh_loader/include/mesh_loader.h \
	srcs/mtl_loader/include/mtl_loader.h \
	srcs/texture_loader/include/texture_loader.h srcs/utils/include/utils.h \
	| o/srcs/mesh_loader/
o/srcs/mesh_loader/build_mtl.o: srcs/mesh_loader/build_mtl.c \
	srcs/math_utils/include/math_utils.h \
	srcs/mesh_loader/include/mesh_loader.h \
	srcs/mtl_loader/include/mtl_loader.h \
	srcs/texture_loader/include/texture_loader.h | o/srcs/mesh_loader/
o/srcs/mesh_loader/load_mesh.o: srcs/mesh_loader/load_mesh.c \
	srcs/math_utils/include/math_utils.h \
	srcs/mesh_loader/include/mesh_loader.h \
	srcs/mtl_loader/include/mtl_loader.h \
	srcs/texture_loader/include/texture_loader.h | o/srcs/mesh_loader/
o/srcs/mesh_loader/parse_mesh.o: srcs/mesh_loader/parse_mesh.c \
	srcs/math_utils/include/math_utils.h \
	srcs/mesh_loader/include/mesh_loader.h \
	srcs/mtl_loader/include/mtl_loader.h \
	srcs/texture_loader/include/texture_loader.h srcs/utils/include/utils.h \
	| o/srcs/mesh_loader/
o/srcs/mesh_loader/parse_mesh_tokens.o: srcs/mesh_loader/parse_mesh_tokens.c \
	srcs/math_utils/include/math_utils.h \
	srcs/mesh_loader/include/mesh_loader.h \
	srcs/mtl_loader/include/mtl_loader.h \
	srcs/texture_loader/include/texture_loader.h srcs/utils/include/utils.h \
	| o/srcs/mesh_loader/
o/srcs/mesh_loader/parse_mesh_tokens_mtl.o: \
	srcs/mesh_loader/parse_mesh_tokens_mtl.c \
	srcs/math_utils/include/math_utils.h \
	srcs/mesh_loader/include/mesh_loader.h \
	srcs/mtl_loader/include/mtl_loader.h \
	srcs/texture_loader/include/texture_loader.h srcs/utils/include/utils.h \
	| o/srcs/mesh_loader/
o/srcs/mesh_loader/send_mesh.o: srcs/mesh_loader/send_mesh.c \
	srcs/math_utils/include/math_utils.h \
	srcs/mesh_loader/include/mesh_loader.h \
	srcs/mtl_loader/include/mtl_loader.h \
	srcs/texture_loader/include/texture_loader.h | o/srcs/mesh_loader/
o/srcs/mtl_loader/load_mtl.o: srcs/mtl_loader/load_mtl.c \
	srcs/math_utils/include/math_utils.h srcs/mtl_loader/include/mtl_loader.h \
	srcs/texture_loader/include/texture_loader.h srcs/utils/include/utils.h \
	| o/srcs/mtl_loader/
o/srcs/mtl_loader/parse_mtl.o: srcs/mtl_loader/parse_mtl.c \
	srcs/math_utils/include/math_utils.h srcs/mtl_loader/include/mtl_loader.h \
	srcs/texture_loader/include/texture_loader.h srcs/utils/include/utils.h \
	| o/srcs/mtl_loader/
o/srcs/mtl_loader/parse_mtl_tokens.o: srcs/mtl_loader/parse_mtl_tokens.c \
	srcs/math_utils/include/math_utils.h srcs/mtl_loader/include/mtl_loader.h \
	srcs/texture_loader/include/texture_loader.h srcs/utils/include/utils.h \
	| o/srcs/mtl_loader/
o/srcs/mtl_loader/parse_mtl_tokens_map.o: \
	srcs/mtl_loader/parse_mtl_tokens_map.c \
	srcs/math_utils/include/math_utils.h srcs/mtl_loader/include/mtl_loader.h \
	srcs/texture_loader/include/texture_loader.h | o/srcs/mtl_loader/
o/srcs/obj_anim/anim_c_move.o: srcs/obj_anim/anim_c_move.c \
	srcs/anim/include/anim.h srcs/math_utils/include/math_utils.h \
	srcs/mesh_loader/include/mesh_loader.h \
	srcs/mtl_loader/include/mtl_loader.h srcs/obj/include/obj.h \
	srcs/obj_anim/include/obj_anim.h \
	srcs/texture_loader/include/texture_loader.h \
	srcs/transform/include/transform.h | o/srcs/obj_anim/
o/srcs/obj_anim/anim_c_rot.o: srcs/obj_anim/anim_c_rot.c \
	srcs/anim/include/anim.h srcs/math_utils/include/math_utils.h \
	srcs/mesh_loader/include/mesh_loader.h \
	srcs/mtl_loader/include/mtl_loader.h srcs/obj/include/obj.h \
	srcs/obj_anim/include/obj_anim.h \
	srcs/texture_loader/include/texture_loader.h \
	srcs/transform/include/transform.h | o/srcs/obj_anim/
o/srcs/obj_anim/anim_c_scale.o: srcs/obj_anim/anim_c_scale.c \
	srcs/anim/include/anim.h srcs/math_utils/include/math_utils.h \
	srcs/mesh_loader/include/mesh_loader.h \
	srcs/mtl_loader/include/mtl_loader.h srcs/obj/include/obj.h \
	srcs/obj_anim/include/obj_anim.h \
	srcs/texture_loader/include/texture_loader.h \
	srcs/transform/include/transform.h | o/srcs/obj_anim/
o/srcs/obj_anim/anim_c_shear.o: srcs/obj_anim/anim_c_shear.c \
	srcs/anim/include/anim.h srcs/math_utils/include/math_utils.h \
	srcs/mesh_loader/include/mesh_loader.h \
	srcs/mtl_loader/include/mtl_loader.h srcs/obj/include/obj.h \
	srcs/obj_anim/include/obj_anim.h \
	srcs/texture_loader/include/texture_loader.h \
	srcs/transform/include/transform.h | o/srcs/obj_anim/
o/srcs/renderer/simple_renderer.o: srcs/renderer/simple_renderer.c \
	srcs/anim/include/anim.h srcs/camera/include/camera.h \
	srcs/math_utils/include/math_utils.h \
	srcs/mesh_loader/include/mesh_loader.h \
	srcs/mtl_loader/include/mtl_loader.h srcs/obj/include/obj.h \
	srcs/renderer/include/renderer.h \
	srcs/texture_loader/include/texture_loader.h \
	srcs/transform/include/transform.h \
	srcs/shader_loader/include/shader_loader.h srcs/utils/include/utils.h \
	| o/srcs/renderer/
o/srcs/shader_loader/compile_shader.o: srcs/shader_loader/compile_shader.c \
	srcs/shader_loader/include/shader_loader.h | o/srcs/shader_loader/
o/srcs/shader_loader/load_shader.o: srcs/shader_loader/load_shader.c \
	srcs/shader_loader/include/shader_loader.h srcs/utils/include/utils.h \
	| o/srcs/shader_loader/
o/srcs/shader_loader/load_uniforms.o: srcs/shader_loader/load_uniforms.c \
	srcs/shader_loader/include/shader_loader.h srcs/utils/include/utils.h \
	| o/srcs/shader_loader/
o/srcs/shader_loader/read_shader.o: srcs/shader_loader/read_shader.c \
	srcs/shader_loader/include/shader_loader.h srcs/utils/include/utils.h \
	| o/srcs/shader_loader/
o/srcs/shader_loader/shader_get_uniform.o: \
	srcs/shader_loader/shader_get_uniform.c \
	srcs/shader_loader/include/shader_loader.h | o/srcs/shader_loader/
o/srcs/texture_loader/ft_loadimage.o: srcs/texture_loader/ft_loadimage.c \
	srcs/texture_loader/include/texture_loader.h | o/srcs/texture_loader/
o/srcs/texture_loader/load_texture.o: srcs/texture_loader/load_texture.c \
	srcs/texture_loader/include/texture_loader.h | o/srcs/texture_loader/
o/srcs/texture_loader/tga_parser.o: srcs/texture_loader/tga_parser.c \
	srcs/texture_loader/include/texture_loader.h srcs/utils/include/utils.h \
	| o/srcs/texture_loader/
o/srcs/transform/ft_transform_get.o: srcs/transform/ft_transform_get.c \
	srcs/math_utils/include/math_utils.h srcs/transform/include/transform.h \
	| o/srcs/transform/
o/srcs/transform/ft_transform_move.o: srcs/transform/ft_transform_move.c \
	srcs/math_utils/include/math_utils.h srcs/transform/include/transform.h \
	| o/srcs/transform/
o/srcs/transform/ft_transform_reflect.o: srcs/transform/ft_transform_reflect.c \
	srcs/math_utils/include/math_utils.h srcs/transform/include/transform.h \
	| o/srcs/transform/
o/srcs/transform/ft_transform_rotate.o: srcs/transform/ft_transform_rotate.c \
	srcs/math_utils/include/math_utils.h srcs/transform/include/transform.h \
	| o/srcs/transform/
o/srcs/transform/ft_transform_scale.o: srcs/transform/ft_transform_scale.c \
	srcs/math_utils/include/math_utils.h srcs/transform/include/transform.h \
	| o/srcs/transform/
o/srcs/transform/ft_transform_shear.o: srcs/transform/ft_transform_shear.c \
	srcs/math_utils/include/math_utils.h srcs/transform/include/transform.h \
	| o/srcs/transform/
o/srcs/utils/fps.o: srcs/utils/fps.c srcs/utils/include/utils.h | o/srcs/utils/
o/srcs/utils/ft_error.o: srcs/utils/ft_error.c srcs/utils/include/utils.h \
	| o/srcs/utils/
o/srcs/utils/ft_listremove_next.o: srcs/utils/ft_listremove_next.c \
	srcs/utils/include/utils.h | o/srcs/utils/
o/srcs/utils/ft_subends.o: srcs/utils/ft_subends.c srcs/utils/include/utils.h \
	| o/srcs/utils/
o/srcs/utils/ft_substart.o: srcs/utils/ft_substart.c \
	srcs/utils/include/utils.h | o/srcs/utils/
o/srcs/utils/parse_fvec.o: srcs/utils/parse_fvec.c srcs/utils/include/utils.h \
	| o/srcs/utils/
