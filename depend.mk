O_FILES :=	o/srcs/init_window.o o/srcs/key_events.o o/srcs/main.o \
			o/srcs/math_utils/ft_mat4identity.o \
			o/srcs/math_utils/ft_mat4look_at.o o/srcs/math_utils/ft_mat4mult.o \
			o/srcs/math_utils/ft_mat4perspective.o \
			o/srcs/math_utils/ft_mat4rotate.o o/srcs/math_utils/ft_mat4scale.o \
			o/srcs/math_utils/ft_mat4translate.o \
			o/srcs/math_utils/ft_vec3cross.o o/srcs/math_utils/ft_vec3dot.o \
			o/srcs/math_utils/ft_vec3norm.o o/srcs/math_utils/ft_vec3rotate.o \
			o/srcs/math_utils/ft_vec3sub.o o/srcs/mesh_loader/build_mesh.o \
			o/srcs/mesh_loader/load_mesh.o o/srcs/mesh_loader/parse_mesh.o \
			o/srcs/mesh_loader/parse_mesh_tokens.o \
			o/srcs/mesh_loader/send_mesh.o o/srcs/mtl_loader/load_mtl.o \
			o/srcs/mtl_loader/parse_mtl.o o/srcs/mtl_loader/parse_mtl_token.o \
			o/srcs/resources/get_res.o o/srcs/resources/res_loaders.o \
			o/srcs/shader_loader/load_shader.o \
			o/srcs/texture_loader/ft_loadimage.o \
			o/srcs/texture_loader/load_texture.o \
			o/srcs/texture_loader/tga_parser.o o/srcs/utils/parse_fvec.o

o/srcs/init_window.o: srcs/init_window.c include/scop.h include/gl.h \
	include/shader_loader.h include/mesh_loader.h include/mtl_loader.h \
	include/texture_loader.h include/math_utils.h include/math_utils.h \
	include/texture_loader.h | o/srcs/
o/srcs/key_events.o: srcs/key_events.c include/scop.h include/gl.h \
	include/shader_loader.h include/mesh_loader.h include/mtl_loader.h \
	include/texture_loader.h include/math_utils.h include/math_utils.h \
	include/texture_loader.h include/utils.h include/gl.h | o/srcs/
o/srcs/main.o: srcs/main.c include/scop.h include/gl.h include/shader_loader.h \
	include/mesh_loader.h include/mtl_loader.h include/texture_loader.h \
	include/math_utils.h include/math_utils.h include/texture_loader.h \
	include/resources.h include/math_utils.h include/utils.h | o/srcs/
o/srcs/math_utils/ft_mat4identity.o: srcs/math_utils/ft_mat4identity.c \
	include/math_utils.h | o/srcs/math_utils/
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
o/srcs/math_utils/ft_vec3cross.o: srcs/math_utils/ft_vec3cross.c \
	include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_vec3dot.o: srcs/math_utils/ft_vec3dot.c \
	include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_vec3norm.o: srcs/math_utils/ft_vec3norm.c \
	include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_vec3rotate.o: srcs/math_utils/ft_vec3rotate.c \
	include/math_utils.h | o/srcs/math_utils/
o/srcs/math_utils/ft_vec3sub.o: srcs/math_utils/ft_vec3sub.c \
	include/math_utils.h | o/srcs/math_utils/
o/srcs/mesh_loader/build_mesh.o: srcs/mesh_loader/build_mesh.c \
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
o/srcs/mesh_loader/send_mesh.o: srcs/mesh_loader/send_mesh.c \
	include/mesh_loader.h include/mtl_loader.h include/texture_loader.h \
	include/math_utils.h include/math_utils.h include/gl.h | o/srcs/mesh_loader/
o/srcs/mtl_loader/load_mtl.o: srcs/mtl_loader/load_mtl.c include/mtl_loader.h \
	include/texture_loader.h include/math_utils.h include/utils.h \
	| o/srcs/mtl_loader/
o/srcs/mtl_loader/parse_mtl.o: srcs/mtl_loader/parse_mtl.c \
	include/mtl_loader.h include/texture_loader.h include/math_utils.h \
	include/utils.h | o/srcs/mtl_loader/
o/srcs/mtl_loader/parse_mtl_token.o: srcs/mtl_loader/parse_mtl_token.c \
	include/mtl_loader.h include/texture_loader.h include/math_utils.h \
	include/utils.h include/resources.h | o/srcs/mtl_loader/
o/srcs/resources/get_res.o: srcs/resources/get_res.c include/resources.h \
	include/shader_loader.h include/mesh_loader.h include/mtl_loader.h \
	include/texture_loader.h include/math_utils.h include/math_utils.h \
	include/mtl_loader.h include/texture_loader.h include/math_utils.h \
	include/texture_loader.h include/utils.h | o/srcs/resources/
o/srcs/resources/res_loaders.o: srcs/resources/res_loaders.c \
	include/resources.h include/shader_loader.h include/mesh_loader.h \
	include/mtl_loader.h include/texture_loader.h include/math_utils.h \
	include/math_utils.h include/mtl_loader.h include/texture_loader.h \
	include/math_utils.h include/texture_loader.h | o/srcs/resources/
o/srcs/shader_loader/load_shader.o: srcs/shader_loader/load_shader.c \
	include/shader_loader.h include/gl.h | o/srcs/shader_loader/
o/srcs/texture_loader/ft_loadimage.o: srcs/texture_loader/ft_loadimage.c \
	include/texture_loader.h | o/srcs/texture_loader/
o/srcs/texture_loader/load_texture.o: srcs/texture_loader/load_texture.c \
	include/texture_loader.h include/scop.h include/gl.h \
	include/shader_loader.h include/mesh_loader.h include/mtl_loader.h \
	include/texture_loader.h include/math_utils.h include/math_utils.h \
	include/texture_loader.h | o/srcs/texture_loader/
o/srcs/texture_loader/tga_parser.o: srcs/texture_loader/tga_parser.c \
	include/texture_loader.h | o/srcs/texture_loader/
o/srcs/utils/parse_fvec.o: srcs/utils/parse_fvec.c include/utils.h \
	| o/srcs/utils/
