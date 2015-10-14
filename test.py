# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juloo <juloo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/14 22:44:53 by juloo             #+#    #+#              #
#    Updated: 2015/10/14 23:50:49 by juloo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class ModuleDef():

	def __init__(self, module_dir):

		self.module_dir = module_dir
		self.include_dirs = []
		self.public_required = []
		self.private_required = []
		self.to_put = {}
		self.locals = []
		self.auto_enabled = True
		self.defaultRecipes = []
		self.targets = []

	# 'include' instructor
	def include(self, dirs):
		for d in dirs:
			if not d in self.include_dirs:
				self.include_dirs.append(d)

	# 'require' instruction
	def require(self, module, public):
		if public:
			if not module in self.public_required:
				self.public_required.append(module)
		else:
			if not module in self.private_required:
				self.private_required.append(module)

	# 'put' instruction
	def put(self, var, words):
		if not var in self.to_put:
			to_put[var] = []
		for w in words:
			if not w in to_put[var]:
				to_put[var].append(w)

	# 'local' instruction
	def local(self, code):
		self.locals.append(code)

	# 'disable' instruction
	def disable(self, key):
		if key == "auto":
			self.auto_enabled = False
		else:
			raise "Cannot disable %s" % key

	# 'recipe' instruction
	def recipe(self, code):
		if len(self.targets) == 0:
			self.defaultRecipes.append(code)
		else:
			self.targets[-1][1].append(code)

	# 'target' instruction
	def target(self, code):
		self.targets.append((code, []))



MODULE_INSTRUCTIONS = {
	"include": lambda m, w, v: ModuleDef.include(m, w),
	"require": (lambda m, w, v:
			if len(w) != 1:
				raise "Bad number of argument for 'require'"
			ModuleDef.require(m, w[0], v == "public")
	),
	"put": (lambda m, w, v:
			if len(w) < 2:
				raise "Not enougth argument for 'put'"
			ModuleDef.put(m, w[0], w[1:])
	),
	"local": (lambda m, w, v:
			if len(w) < 1:
				raise "Not enougth argument for 'local'"
			ModuleDef.local(m, " ".join(w))
	),
	"disable": (lambda m, w, v:
			if len(w) != 1:
				raise "Bad number of argument for 'disable'"
			ModuleDef.disable(m, w[0])
	),
	"recipe": (lambda m, w, v:
			if len(w) < 1:
				raise "Not enougth argument for 'recipe'"
			ModuleDef.recipe(m, " ".join(w))
	),
	"target": (lambda m, w, v:
			if len(w) < 1:
				raise "Not enougth argument for 'target'"
			ModuleDef.target(m, " ".join(w))
	)
}

def parse_module_file(file_name):
	modules = []
	current_module = None
	try:
		with open(file_name, "r") as f:
			line_n = 0
			for f_line in f:
				line_n += 1
				line = f_line.lstrip()
				if line.find("#") >= 0:
					line = line.split("#")[0]
				line = line.rstrip()
				if len(line) == 0:
					continue
				words = line.split()
				visiblity = None
				if words[0] in ["public", "private"]:
					visiblity = words[0]
					words = words[1:]
					if len(words) == 0:
						print "Error: Useless %s at line %d \"%s\"" % (visiblity, line_n, f_line)
						break
				if words[0] == "module":
					if not len(words) in [2, 3]:
						print "Error: %s argument for 'module' at line %d \"%s\"" % (
							"Not enougth" if len(words) < 2 else "Too many"
							line_n, f_line
						)
						break
					if words[0].endswith(":")
						words[0] = words[0][:-1]
					current_module = ModuleDef(words[2] if len(words) == 3 else ".")
					modules.append(current_module)
				elif words[0] in MODULE_INSTRUCTIONS:
					try:
						MODULE_INSTRUCTIONS[words[0]](current_module, words[1:], visiblity)
					except str as e:
						print "Error: %s at line %d \"%s\"" % (e, line_n, f_line)
						break
				else:
					print "Error: Unknow instruction '%s' at line %d \"%s\"" % (words[0], line_n, f_line)
					break
	except:
		print "Warning: Cannot open %s" % file_name
		return []
	return modules
