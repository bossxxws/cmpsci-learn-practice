import random
from deap import base, creator, tools, algorithms
import numpy as np
# 定义一个复杂的适应度函数
def evalFitness(individual):
    x = individual[0]
    # 定义一个复杂的函数，其中包含目标数值作为一部分
    fitness_value = np.sin(x) * np.cos(x**2) + (x - 1.4301614378721832*3)**2
    return (fitness_value,)
# 创建遗传算法的类型
creator.create("FitnessMax", base.Fitness, weights=(1.0,))  # 我们要最大化适应度
creator.create("Individual", list, fitness=creator.FitnessMax)
# 工具箱配置
toolbox = base.Toolbox()
toolbox.register("attr_float", random.uniform, -10, 10)  # 浮点数个体
toolbox.register("individual", tools.initRepeat, creator.Individual, toolbox.attr_float, n=1)
toolbox.register("population", tools.initRepeat, list, toolbox.individual)
toolbox.register("evaluate", evalFitness)
toolbox.register("mate", tools.cxBlend, alpha=0.5)
toolbox.register("mutate", tools.mutGaussian, mu=0, sigma=1, indpb=0.2)
toolbox.register("select", tools.selTournament, tournsize=3)
# 初始化种群
population = toolbox.population(n=300)
# 算法参数
ngen = 40  # 代数
cxpb = 0.5  # 交叉概率
mutpb = 0.2  # 突变概率
# 运行遗传算法
for gen in range(ngen):
    # 选择下一代个体
    offspring = toolbox.select(population, len(population))
    offspring = list(map(toolbox.clone, offspring))
    # 交叉和突变
    for child1, child2 in zip(offspring[::2], offspring[1::2]):
        if random.random() < cxpb:
            toolbox.mate(child1, child2)
            del child1.fitness.values
            del child2.fitness.values
    for mutant in offspring:
        if random.random() < mutpb:
            toolbox.mutate(mutant)
            del mutant.fitness.values
    # 评估个体适应度
    invalid_ind = [ind for ind in offspring if not ind.fitness.valid]
    fitnesses = map(toolbox.evaluate, invalid_ind)
    for ind, fit in zip(invalid_ind, fitnesses):
        ind.fitness.values = fit
    # 更新种群
    population[:] = offspring
    # 打印当前最佳个体
    fits = [ind.fitness.values[0] for ind in population]
    best_ind = tools.selBest(population, 1)[0]
    print(f"Generation {gen}: Best fit = {best_ind[0]}, Best value = {best_ind.fitness.values[0]}")
# 输出最终的最佳个体
best_ind = tools.selBest(population, 1)[0]
print(f"Best individual is {best_ind}, with fitness: {best_ind.fitness.values[0]}")