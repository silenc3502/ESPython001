import math

def poisson_dist_prob(poisson_lambda, event_num):
	return math.exp(-(poisson_lambda)) * poisson_lambda ** event_num / math.factorial(event_num)

prob = poisson_dist_prob(10, 0)
print("poisson_dist(10, 0) = {0}%".format(prob * 100))
