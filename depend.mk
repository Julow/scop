LINK_DEPENDS += libft/libft.a
LINK_FLAGS += -Llibft -lft -lm
LIBS_RULES += libft
O_FILES += $(O_DIR)/srcs/anim/anim_start.o $(O_DIR)/srcs/anim/anim_update.o \
	$(O_DIR)/srcs/anim/smooth_back_in.o \
	$(O_DIR)/srcs/anim/smooth_back_in_out.o \
	$(O_DIR)/srcs/anim/smooth_back_out.o $(O_DIR)/srcs/anim/smooth_bounce.o \
	$(O_DIR)/srcs/anim/smooth_elastic.o $(O_DIR)/srcs/anim/smooth_in.o \
	$(O_DIR)/srcs/anim/smooth_in_out.o $(O_DIR)/srcs/anim/smooth_linear.o \
	$(O_DIR)/srcs/anim/smooth_out.o $(O_DIR)/srcs/camera/camera_get_view.o \
	$(O_DIR)/srcs/camera/camera_look.o $(O_DIR)/srcs/camera/camera_move.o \
	$(O_DIR)/srcs/events/events.o $(O_DIR)/srcs/math_utils/ft_mat4look_at.o \
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
	$(O_DIR)/srcs/math_utils/ft_vec3sub.o $(O_DIR)/srcs/obj_anim/anim_c_move.o \
	$(O_DIR)/srcs/obj_anim/anim_c_rot.o $(O_DIR)/srcs/obj_anim/anim_c_scale.o \
	$(O_DIR)/srcs/obj_anim/anim_c_shear.o \
	$(O_DIR)/srcs/renderer/depth_renderer.o $(O_DIR)/srcs/renderer/renderers.o \
	$(O_DIR)/srcs/renderer/simple_renderer.o \
	$(O_DIR)/srcs/transform/ft_transform_get.o \
	$(O_DIR)/srcs/transform/ft_transform_move.o \
	$(O_DIR)/srcs/transform/ft_transform_reflect.o \
	$(O_DIR)/srcs/transform/ft_transform_rotate.o \
	$(O_DIR)/srcs/transform/ft_transform_scale.o \
	$(O_DIR)/srcs/transform/ft_transform_shear.o $(O_DIR)/srcs/utils/fps.o \
	$(O_DIR)/srcs/utils/ft_error.o $(O_DIR)/srcs/utils/ft_listremove_next.o \
	$(O_DIR)/srcs/utils/ft_subends.o $(O_DIR)/srcs/utils/ft_substart.o \
	$(O_DIR)/srcs/utils/parse_fvec.o \
	$(O_DIR)/srcs/shader_loader/compile_shader.o \
	$(O_DIR)/srcs/shader_loader/load_shader.o \
	$(O_DIR)/srcs/shader_loader/load_uniforms.o \
	$(O_DIR)/srcs/shader_loader/read_shader.o \
	$(O_DIR)/srcs/shader_loader/shader_get_uniform.o \
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
	$(O_DIR)/srcs/texture_loader/ft_loadimage.o \
	$(O_DIR)/srcs/texture_loader/load_texture.o \
	$(O_DIR)/srcs/texture_loader/tga_parser.o $(O_DIR)/srcs/main/callbacks.o \
	$(O_DIR)/srcs/main/init_window.o $(O_DIR)/srcs/main/main.o \
	$(O_DIR)/srcs/main/motions.o

# module libft
libft:
	make -C libft
.PHONY: libft

# module anim
$(O_DIR)/srcs/anim/anim_start.o: INCLUDE_FLAGS += -Ilibft -Isrcs/anim/include
$(O_DIR)/srcs/anim/anim_start.o: srcs/anim/anim_start.c libft/libft.h \
	srcs/anim/include/anim.h | $(O_DIR)/srcs/anim/
$(O_DIR)/srcs/anim/anim_update.o: INCLUDE_FLAGS += -Ilibft -Isrcs/anim/include
$(O_DIR)/srcs/anim/anim_update.o: srcs/anim/anim_update.c libft/libft.h \
	srcs/anim/include/anim.h | $(O_DIR)/srcs/anim/
$(O_DIR)/srcs/anim/smooth_back_in.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/anim/include
$(O_DIR)/srcs/anim/smooth_back_in.o: srcs/anim/smooth_back_in.c libft/libft.h \
	srcs/anim/include/anim.h | $(O_DIR)/srcs/anim/
$(O_DIR)/srcs/anim/smooth_back_in_out.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/anim/include
$(O_DIR)/srcs/anim/smooth_back_in_out.o: srcs/anim/smooth_back_in_out.c \
	libft/libft.h srcs/anim/include/anim.h | $(O_DIR)/srcs/anim/
$(O_DIR)/srcs/anim/smooth_back_out.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/anim/include
$(O_DIR)/srcs/anim/smooth_back_out.o: srcs/anim/smooth_back_out.c \
	libft/libft.h srcs/anim/include/anim.h | $(O_DIR)/srcs/anim/
$(O_DIR)/srcs/anim/smooth_bounce.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/anim/include
$(O_DIR)/srcs/anim/smooth_bounce.o: srcs/anim/smooth_bounce.c libft/libft.h \
	srcs/anim/include/anim.h | $(O_DIR)/srcs/anim/
$(O_DIR)/srcs/anim/smooth_elastic.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/anim/include
$(O_DIR)/srcs/anim/smooth_elastic.o: srcs/anim/smooth_elastic.c libft/libft.h \
	srcs/anim/include/anim.h | $(O_DIR)/srcs/anim/
$(O_DIR)/srcs/anim/smooth_in.o: INCLUDE_FLAGS += -Ilibft -Isrcs/anim/include
$(O_DIR)/srcs/anim/smooth_in.o: srcs/anim/smooth_in.c libft/libft.h \
	srcs/anim/include/anim.h | $(O_DIR)/srcs/anim/
$(O_DIR)/srcs/anim/smooth_in_out.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/anim/include
$(O_DIR)/srcs/anim/smooth_in_out.o: srcs/anim/smooth_in_out.c libft/libft.h \
	srcs/anim/include/anim.h | $(O_DIR)/srcs/anim/
$(O_DIR)/srcs/anim/smooth_linear.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/anim/include
$(O_DIR)/srcs/anim/smooth_linear.o: srcs/anim/smooth_linear.c libft/libft.h \
	srcs/anim/include/anim.h | $(O_DIR)/srcs/anim/
$(O_DIR)/srcs/anim/smooth_out.o: INCLUDE_FLAGS += -Ilibft -Isrcs/anim/include
$(O_DIR)/srcs/anim/smooth_out.o: srcs/anim/smooth_out.c libft/libft.h \
	srcs/anim/include/anim.h | $(O_DIR)/srcs/anim/

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

# module events
$(O_DIR)/srcs/events/events.o: INCLUDE_FLAGS += -Ilibft -Isrcs/events/include \
	-Isrcs/gl -Isrcs/utils/include
$(O_DIR)/srcs/events/events.o: srcs/events/events.c libft/libft.h \
	srcs/events/include/events.h srcs/gl/gl.h srcs/gl/gl.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/events/

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

# module obj

# module obj_anim
$(O_DIR)/srcs/obj_anim/anim_c_move.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/anim/include -Isrcs/camera/include -Isrcs/math_utils/include \
	-Isrcs/mesh -Isrcs/mtl -Isrcs/obj/include -Isrcs/obj_anim/include \
	-Isrcs/texture -Isrcs/transform/include
$(O_DIR)/srcs/obj_anim/anim_c_move.o: srcs/obj_anim/anim_c_move.c \
	libft/libft.h srcs/anim/include/anim.h srcs/camera/include/camera.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/obj/include/obj.h \
	srcs/obj_anim/include/obj_anim.h srcs/texture/texture.h \
	srcs/transform/include/transform.h | $(O_DIR)/srcs/obj_anim/
$(O_DIR)/srcs/obj_anim/anim_c_rot.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/anim/include -Isrcs/camera/include -Isrcs/math_utils/include \
	-Isrcs/mesh -Isrcs/mtl -Isrcs/obj/include -Isrcs/obj_anim/include \
	-Isrcs/texture -Isrcs/transform/include
$(O_DIR)/srcs/obj_anim/anim_c_rot.o: srcs/obj_anim/anim_c_rot.c libft/libft.h \
	srcs/anim/include/anim.h srcs/camera/include/camera.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/obj/include/obj.h \
	srcs/obj_anim/include/obj_anim.h srcs/texture/texture.h \
	srcs/transform/include/transform.h | $(O_DIR)/srcs/obj_anim/
$(O_DIR)/srcs/obj_anim/anim_c_scale.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/anim/include -Isrcs/camera/include -Isrcs/math_utils/include \
	-Isrcs/mesh -Isrcs/mtl -Isrcs/obj/include -Isrcs/obj_anim/include \
	-Isrcs/texture -Isrcs/transform/include
$(O_DIR)/srcs/obj_anim/anim_c_scale.o: srcs/obj_anim/anim_c_scale.c \
	libft/libft.h srcs/anim/include/anim.h srcs/camera/include/camera.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/obj/include/obj.h \
	srcs/obj_anim/include/obj_anim.h srcs/texture/texture.h \
	srcs/transform/include/transform.h | $(O_DIR)/srcs/obj_anim/
$(O_DIR)/srcs/obj_anim/anim_c_shear.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/anim/include -Isrcs/camera/include -Isrcs/math_utils/include \
	-Isrcs/mesh -Isrcs/mtl -Isrcs/obj/include -Isrcs/obj_anim/include \
	-Isrcs/texture -Isrcs/transform/include
$(O_DIR)/srcs/obj_anim/anim_c_shear.o: srcs/obj_anim/anim_c_shear.c \
	libft/libft.h srcs/anim/include/anim.h srcs/camera/include/camera.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/obj/include/obj.h \
	srcs/obj_anim/include/obj_anim.h srcs/texture/texture.h \
	srcs/transform/include/transform.h | $(O_DIR)/srcs/obj_anim/

# module renderer
$(O_DIR)/srcs/renderer/depth_renderer.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/anim/include -Isrcs/camera/include -Isrcs/gl \
	-Isrcs/math_utils/include -Isrcs/mesh -Isrcs/mtl -Isrcs/obj/include \
	-Isrcs/renderer/include -Isrcs/renderer/include/public -Isrcs/shader \
	-Isrcs/shader_loader/include/public -Isrcs/texture \
	-Isrcs/transform/include -Isrcs/utils/include
$(O_DIR)/srcs/renderer/depth_renderer.o: srcs/renderer/depth_renderer.c \
	libft/libft.h srcs/anim/include/anim.h srcs/camera/include/camera.h \
	srcs/camera/include/camera.h srcs/gl/gl.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/renderer/include/public/renderer.h \
	srcs/renderer/include/renderers.h srcs/shader/shader.h \
	srcs/shader/shader.h srcs/shader_loader/include/public/shader_loader.h \
	srcs/texture/texture.h srcs/transform/include/transform.h \
	| $(O_DIR)/srcs/renderer/
$(O_DIR)/srcs/renderer/renderers.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/anim/include -Isrcs/camera/include -Isrcs/gl \
	-Isrcs/math_utils/include -Isrcs/mesh -Isrcs/mtl -Isrcs/obj/include \
	-Isrcs/renderer/include -Isrcs/renderer/include/public -Isrcs/shader \
	-Isrcs/shader_loader/include/public -Isrcs/texture \
	-Isrcs/transform/include -Isrcs/utils/include
$(O_DIR)/srcs/renderer/renderers.o: srcs/renderer/renderers.c libft/libft.h \
	srcs/anim/include/anim.h srcs/camera/include/camera.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/renderer/include/public/renderer.h \
	srcs/renderer/include/renderers.h srcs/texture/texture.h \
	srcs/transform/include/transform.h | $(O_DIR)/srcs/renderer/
$(O_DIR)/srcs/renderer/simple_renderer.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/anim/include -Isrcs/camera/include -Isrcs/gl \
	-Isrcs/math_utils/include -Isrcs/mesh -Isrcs/mtl -Isrcs/obj/include \
	-Isrcs/renderer/include -Isrcs/renderer/include/public -Isrcs/shader \
	-Isrcs/shader_loader/include/public -Isrcs/texture \
	-Isrcs/transform/include -Isrcs/utils/include
$(O_DIR)/srcs/renderer/simple_renderer.o: srcs/renderer/simple_renderer.c \
	libft/ft_hmap.h libft/libft.h srcs/anim/include/anim.h \
	srcs/camera/include/camera.h srcs/camera/include/camera.h srcs/gl/gl.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h srcs/mesh/mesh.h \
	srcs/mtl/mtl.h srcs/mtl/mtl.h srcs/obj/include/obj.h \
	srcs/obj/include/obj.h srcs/renderer/include/public/renderer.h \
	srcs/shader/shader.h srcs/shader_loader/include/public/shader_loader.h \
	srcs/texture/texture.h srcs/texture/texture.h \
	srcs/transform/include/transform.h srcs/utils/include/utils.h \
	| $(O_DIR)/srcs/renderer/

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

# module utils
$(O_DIR)/srcs/utils/fps.o: INCLUDE_FLAGS += -Ilibft -Isrcs/utils/include
$(O_DIR)/srcs/utils/fps.o: srcs/utils/fps.c libft/libft.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/utils/
$(O_DIR)/srcs/utils/ft_error.o: INCLUDE_FLAGS += -Ilibft -Isrcs/utils/include
$(O_DIR)/srcs/utils/ft_error.o: srcs/utils/ft_error.c libft/ft_hmap.h \
	libft/ft_internal.h libft/ft_out.h libft/libft.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/utils/
$(O_DIR)/srcs/utils/ft_listremove_next.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/utils/include
$(O_DIR)/srcs/utils/ft_listremove_next.o: srcs/utils/ft_listremove_next.c \
	libft/ft_list.h libft/libft.h srcs/utils/include/utils.h \
	| $(O_DIR)/srcs/utils/
$(O_DIR)/srcs/utils/ft_subends.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/utils/include
$(O_DIR)/srcs/utils/ft_subends.o: srcs/utils/ft_subends.c libft/libft.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/utils/
$(O_DIR)/srcs/utils/ft_substart.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/utils/include
$(O_DIR)/srcs/utils/ft_substart.o: srcs/utils/ft_substart.c libft/libft.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/utils/
$(O_DIR)/srcs/utils/parse_fvec.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/utils/include
$(O_DIR)/srcs/utils/parse_fvec.o: srcs/utils/parse_fvec.c libft/ft_evalexpr.h \
	libft/libft.h srcs/utils/include/utils.h | $(O_DIR)/srcs/utils/

# module shader

# module shader_loader
$(O_DIR)/srcs/shader_loader/compile_shader.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/gl -Isrcs/shader -Isrcs/shader_loader/include \
	-Isrcs/shader_loader/include/public -Isrcs/utils/include
$(O_DIR)/srcs/shader_loader/compile_shader.o: \
	srcs/shader_loader/compile_shader.c libft/ft_colors.h libft/ft_list.h \
	libft/libft.h srcs/gl/gl.h srcs/shader/shader.h \
	srcs/shader_loader/include/internal.h \
	srcs/shader_loader/include/public/shader_loader.h \
	| $(O_DIR)/srcs/shader_loader/
$(O_DIR)/srcs/shader_loader/load_shader.o: INCLUDE_FLAGS += -Ilibft -Isrcs/gl \
	-Isrcs/shader -Isrcs/shader_loader/include \
	-Isrcs/shader_loader/include/public -Isrcs/utils/include
$(O_DIR)/srcs/shader_loader/load_shader.o: srcs/shader_loader/load_shader.c \
	libft/ft_hmap.h libft/ft_list.h libft/libft.h srcs/gl/gl.h \
	srcs/shader/shader.h srcs/shader_loader/include/internal.h \
	srcs/shader_loader/include/public/shader_loader.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/shader_loader/
$(O_DIR)/srcs/shader_loader/load_uniforms.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/gl -Isrcs/shader -Isrcs/shader_loader/include \
	-Isrcs/shader_loader/include/public -Isrcs/utils/include
$(O_DIR)/srcs/shader_loader/load_uniforms.o: \
	srcs/shader_loader/load_uniforms.c libft/ft_hmap.h libft/libft.h \
	srcs/gl/gl.h srcs/shader/shader.h srcs/shader_loader/include/internal.h \
	srcs/shader_loader/include/public/shader_loader.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/shader_loader/
$(O_DIR)/srcs/shader_loader/read_shader.o: INCLUDE_FLAGS += -Ilibft -Isrcs/gl \
	-Isrcs/shader -Isrcs/shader_loader/include \
	-Isrcs/shader_loader/include/public -Isrcs/utils/include
$(O_DIR)/srcs/shader_loader/read_shader.o: srcs/shader_loader/read_shader.c \
	libft/ft_list.h libft/libft.h srcs/gl/gl.h srcs/shader/shader.h \
	srcs/shader_loader/include/internal.h \
	srcs/shader_loader/include/public/shader_loader.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/shader_loader/
$(O_DIR)/srcs/shader_loader/shader_get_uniform.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/gl -Isrcs/shader -Isrcs/shader_loader/include \
	-Isrcs/shader_loader/include/public -Isrcs/utils/include
$(O_DIR)/srcs/shader_loader/shader_get_uniform.o: \
	srcs/shader_loader/shader_get_uniform.c libft/ft_hmap.h libft/libft.h \
	srcs/shader/shader.h srcs/shader_loader/include/internal.h \
	srcs/shader_loader/include/public/shader_loader.h \
	| $(O_DIR)/srcs/shader_loader/

# module mesh

# module mesh_loader
$(O_DIR)/srcs/mesh_loader/build_mesh.o: INCLUDE_FLAGS += -Ilibft -Isrcs/gl \
	-Isrcs/math_utils/include -Isrcs/mesh -Isrcs/mesh_loader/include \
	-Isrcs/mesh_loader/include/public -Isrcs/mtl \
	-Isrcs/mtl_loader/include/public -Isrcs/texture -Isrcs/utils/include
$(O_DIR)/srcs/mesh_loader/build_mesh.o: srcs/mesh_loader/build_mesh.c \
	libft/ft_hmap.h libft/ft_vector.h libft/libft.h \
	srcs/math_utils/include/math_utils.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h srcs/utils/include/utils.h \
	| $(O_DIR)/srcs/mesh_loader/
$(O_DIR)/srcs/mesh_loader/build_mtl.o: INCLUDE_FLAGS += -Ilibft -Isrcs/gl \
	-Isrcs/math_utils/include -Isrcs/mesh -Isrcs/mesh_loader/include \
	-Isrcs/mesh_loader/include/public -Isrcs/mtl \
	-Isrcs/mtl_loader/include/public -Isrcs/texture -Isrcs/utils/include
$(O_DIR)/srcs/mesh_loader/build_mtl.o: srcs/mesh_loader/build_mtl.c \
	libft/ft_hmap.h libft/ft_vector.h libft/libft.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h \
	srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h | $(O_DIR)/srcs/mesh_loader/
$(O_DIR)/srcs/mesh_loader/load_mesh.o: INCLUDE_FLAGS += -Ilibft -Isrcs/gl \
	-Isrcs/math_utils/include -Isrcs/mesh -Isrcs/mesh_loader/include \
	-Isrcs/mesh_loader/include/public -Isrcs/mtl \
	-Isrcs/mtl_loader/include/public -Isrcs/texture -Isrcs/utils/include
$(O_DIR)/srcs/mesh_loader/load_mesh.o: srcs/mesh_loader/load_mesh.c \
	libft/ft_hmap.h libft/ft_hmap.h libft/ft_vector.h libft/libft.h \
	srcs/math_utils/include/math_utils.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h | $(O_DIR)/srcs/mesh_loader/
$(O_DIR)/srcs/mesh_loader/parse_mesh.o: INCLUDE_FLAGS += -Ilibft -Isrcs/gl \
	-Isrcs/math_utils/include -Isrcs/mesh -Isrcs/mesh_loader/include \
	-Isrcs/mesh_loader/include/public -Isrcs/mtl \
	-Isrcs/mtl_loader/include/public -Isrcs/texture -Isrcs/utils/include
$(O_DIR)/srcs/mesh_loader/parse_mesh.o: srcs/mesh_loader/parse_mesh.c \
	libft/ft_hmap.h libft/ft_vector.h libft/libft.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h \
	srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h srcs/utils/include/utils.h \
	| $(O_DIR)/srcs/mesh_loader/
$(O_DIR)/srcs/mesh_loader/parse_mesh_tokens.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/gl -Isrcs/math_utils/include -Isrcs/mesh -Isrcs/mesh_loader/include \
	-Isrcs/mesh_loader/include/public -Isrcs/mtl \
	-Isrcs/mtl_loader/include/public -Isrcs/texture -Isrcs/utils/include
$(O_DIR)/srcs/mesh_loader/parse_mesh_tokens.o: \
	srcs/mesh_loader/parse_mesh_tokens.c libft/ft_hmap.h libft/ft_vector.h \
	libft/libft.h srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h \
	srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h srcs/utils/include/utils.h \
	| $(O_DIR)/srcs/mesh_loader/
$(O_DIR)/srcs/mesh_loader/parse_mesh_tokens_mtl.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/gl -Isrcs/math_utils/include -Isrcs/mesh -Isrcs/mesh_loader/include \
	-Isrcs/mesh_loader/include/public -Isrcs/mtl \
	-Isrcs/mtl_loader/include/public -Isrcs/texture -Isrcs/utils/include
$(O_DIR)/srcs/mesh_loader/parse_mesh_tokens_mtl.o: \
	srcs/mesh_loader/parse_mesh_tokens_mtl.c libft/ft_hmap.h libft/ft_hmap.h \
	libft/ft_vector.h libft/libft.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/mtl_loader/include/public/mtl_loader.h srcs/texture/texture.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/mesh_loader/
$(O_DIR)/srcs/mesh_loader/send_mesh.o: INCLUDE_FLAGS += -Ilibft -Isrcs/gl \
	-Isrcs/math_utils/include -Isrcs/mesh -Isrcs/mesh_loader/include \
	-Isrcs/mesh_loader/include/public -Isrcs/mtl \
	-Isrcs/mtl_loader/include/public -Isrcs/texture -Isrcs/utils/include
$(O_DIR)/srcs/mesh_loader/send_mesh.o: srcs/mesh_loader/send_mesh.c \
	libft/ft_hmap.h libft/ft_vector.h libft/libft.h srcs/gl/gl.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h \
	srcs/mesh_loader/include/internal.h \
	srcs/mesh_loader/include/public/mesh_loader.h srcs/mtl/mtl.h \
	srcs/texture/texture.h | $(O_DIR)/srcs/mesh_loader/

# module mtl

# module mtl_loader
$(O_DIR)/srcs/mtl_loader/load_mtl.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/math_utils/include -Isrcs/mtl -Isrcs/mtl_loader/include \
	-Isrcs/mtl_loader/include/public -Isrcs/texture \
	-Isrcs/texture_loader/include/public -Isrcs/utils/include
$(O_DIR)/srcs/mtl_loader/load_mtl.o: srcs/mtl_loader/load_mtl.c \
	libft/ft_hmap.h libft/ft_hmap.h libft/libft.h \
	srcs/math_utils/include/math_utils.h srcs/mtl/mtl.h \
	srcs/mtl_loader/include/internal.h \
	srcs/mtl_loader/include/public/mtl_loader.h srcs/texture/texture.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/mtl_loader/
$(O_DIR)/srcs/mtl_loader/parse_mtl.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/math_utils/include -Isrcs/mtl -Isrcs/mtl_loader/include \
	-Isrcs/mtl_loader/include/public -Isrcs/texture \
	-Isrcs/texture_loader/include/public -Isrcs/utils/include
$(O_DIR)/srcs/mtl_loader/parse_mtl.o: srcs/mtl_loader/parse_mtl.c \
	libft/ft_hmap.h libft/ft_hmap.h libft/libft.h \
	srcs/math_utils/include/math_utils.h srcs/mtl/mtl.h \
	srcs/mtl_loader/include/internal.h \
	srcs/mtl_loader/include/public/mtl_loader.h srcs/texture/texture.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/mtl_loader/
$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/math_utils/include -Isrcs/mtl -Isrcs/mtl_loader/include \
	-Isrcs/mtl_loader/include/public -Isrcs/texture \
	-Isrcs/texture_loader/include/public -Isrcs/utils/include
$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens.o: \
	srcs/mtl_loader/parse_mtl_tokens.c libft/ft_hmap.h libft/libft.h \
	srcs/math_utils/include/math_utils.h srcs/mtl/mtl.h \
	srcs/mtl_loader/include/internal.h \
	srcs/mtl_loader/include/public/mtl_loader.h srcs/texture/texture.h \
	srcs/utils/include/utils.h | $(O_DIR)/srcs/mtl_loader/
$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens_map.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/math_utils/include -Isrcs/mtl -Isrcs/mtl_loader/include \
	-Isrcs/mtl_loader/include/public -Isrcs/texture \
	-Isrcs/texture_loader/include/public -Isrcs/utils/include
$(O_DIR)/srcs/mtl_loader/parse_mtl_tokens_map.o: \
	srcs/mtl_loader/parse_mtl_tokens_map.c libft/ft_hmap.h libft/libft.h \
	srcs/math_utils/include/math_utils.h srcs/mtl/mtl.h \
	srcs/mtl_loader/include/internal.h \
	srcs/mtl_loader/include/public/mtl_loader.h srcs/texture/texture.h \
	srcs/texture_loader/include/public/texture_loader.h \
	| $(O_DIR)/srcs/mtl_loader/

# module texture

# module texture_loader
$(O_DIR)/srcs/texture_loader/ft_loadimage.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/gl -Isrcs/texture -Isrcs/texture_loader/include \
	-Isrcs/texture_loader/include/public -Isrcs/utils/include
$(O_DIR)/srcs/texture_loader/ft_loadimage.o: \
	srcs/texture_loader/ft_loadimage.c libft/ft_buff.h libft/ft_buff.h \
	libft/libft.h srcs/texture_loader/include/ft_img.h \
	| $(O_DIR)/srcs/texture_loader/
$(O_DIR)/srcs/texture_loader/load_texture.o: INCLUDE_FLAGS += -Ilibft \
	-Isrcs/gl -Isrcs/texture -Isrcs/texture_loader/include \
	-Isrcs/texture_loader/include/public -Isrcs/utils/include
$(O_DIR)/srcs/texture_loader/load_texture.o: \
	srcs/texture_loader/load_texture.c libft/ft_buff.h libft/ft_hmap.h \
	libft/libft.h srcs/gl/gl.h srcs/texture/texture.h \
	srcs/texture_loader/include/ft_img.h \
	srcs/texture_loader/include/internal.h \
	srcs/texture_loader/include/public/texture_loader.h \
	| $(O_DIR)/srcs/texture_loader/
$(O_DIR)/srcs/texture_loader/tga_parser.o: INCLUDE_FLAGS += -Ilibft -Isrcs/gl \
	-Isrcs/texture -Isrcs/texture_loader/include \
	-Isrcs/texture_loader/include/public -Isrcs/utils/include
$(O_DIR)/srcs/texture_loader/tga_parser.o: srcs/texture_loader/tga_parser.c \
	libft/ft_buff.h libft/ft_buff.h libft/libft.h \
	srcs/texture_loader/include/ft_img.h srcs/utils/include/utils.h \
	| $(O_DIR)/srcs/texture_loader/

# module main
$(O_DIR)/srcs/main/callbacks.o: MDR += lol
$(O_DIR)/srcs/main/callbacks.o: INCLUDE_FLAGS += -Ilibft -Isrcs/anim/include \
	-Isrcs/camera/include -Isrcs/events/include -Isrcs/gl -Isrcs/main/include \
	-Isrcs/math_utils/include -Isrcs/mesh -Isrcs/mesh_loader/include/public \
	-Isrcs/mtl -Isrcs/obj/include -Isrcs/obj_anim/include \
	-Isrcs/renderer/include/public -Isrcs/shader -Isrcs/texture \
	-Isrcs/transform/include -Isrcs/utils/include
$(O_DIR)/srcs/main/callbacks.o: srcs/main/callbacks.c libft/ft_vector.h \
	libft/libft.h srcs/anim/include/anim.h srcs/camera/include/camera.h \
	srcs/events/include/events.h srcs/gl/gl.h srcs/main/include/main.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/renderer/include/public/renderer.h \
	srcs/texture/texture.h srcs/transform/include/transform.h \
	| $(O_DIR)/srcs/main/
$(O_DIR)/srcs/main/init_window.o: MDR += lol
$(O_DIR)/srcs/main/init_window.o: INCLUDE_FLAGS += -Ilibft -Isrcs/anim/include \
	-Isrcs/camera/include -Isrcs/events/include -Isrcs/gl -Isrcs/main/include \
	-Isrcs/math_utils/include -Isrcs/mesh -Isrcs/mesh_loader/include/public \
	-Isrcs/mtl -Isrcs/obj/include -Isrcs/obj_anim/include \
	-Isrcs/renderer/include/public -Isrcs/shader -Isrcs/texture \
	-Isrcs/transform/include -Isrcs/utils/include
$(O_DIR)/srcs/main/init_window.o: srcs/main/init_window.c libft/ft_vector.h \
	libft/libft.h srcs/anim/include/anim.h srcs/camera/include/camera.h \
	srcs/gl/gl.h srcs/main/include/main.h srcs/math_utils/include/math_utils.h \
	srcs/mesh/mesh.h srcs/mtl/mtl.h srcs/obj/include/obj.h \
	srcs/renderer/include/public/renderer.h srcs/texture/texture.h \
	srcs/transform/include/transform.h srcs/utils/include/utils.h \
	| $(O_DIR)/srcs/main/
$(O_DIR)/srcs/main/main.o: MDR += lol
$(O_DIR)/srcs/main/main.o: INCLUDE_FLAGS += -Ilibft -Isrcs/anim/include \
	-Isrcs/camera/include -Isrcs/events/include -Isrcs/gl -Isrcs/main/include \
	-Isrcs/math_utils/include -Isrcs/mesh -Isrcs/mesh_loader/include/public \
	-Isrcs/mtl -Isrcs/obj/include -Isrcs/obj_anim/include \
	-Isrcs/renderer/include/public -Isrcs/shader -Isrcs/texture \
	-Isrcs/transform/include -Isrcs/utils/include
$(O_DIR)/srcs/main/main.o: srcs/main/main.c libft/ft_vector.h libft/libft.h \
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
$(O_DIR)/srcs/main/motions.o: INCLUDE_FLAGS += -Ilibft -Isrcs/anim/include \
	-Isrcs/camera/include -Isrcs/events/include -Isrcs/gl -Isrcs/main/include \
	-Isrcs/math_utils/include -Isrcs/mesh -Isrcs/mesh_loader/include/public \
	-Isrcs/mtl -Isrcs/obj/include -Isrcs/obj_anim/include \
	-Isrcs/renderer/include/public -Isrcs/shader -Isrcs/texture \
	-Isrcs/transform/include -Isrcs/utils/include
$(O_DIR)/srcs/main/motions.o: srcs/main/motions.c libft/ft_vector.h \
	libft/libft.h srcs/anim/include/anim.h srcs/camera/include/camera.h \
	srcs/gl/gl.h srcs/main/include/main.h srcs/main/include/motions.h \
	srcs/math_utils/include/math_utils.h srcs/mesh/mesh.h srcs/mtl/mtl.h \
	srcs/obj/include/obj.h srcs/renderer/include/public/renderer.h \
	srcs/texture/texture.h srcs/transform/include/transform.h \
	| $(O_DIR)/srcs/main/

# module gl
