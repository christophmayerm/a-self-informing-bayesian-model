import stan
import numpy as np

schools_code = """
data {
  int<lower=0> J;         // number of schools
  array[J] real y;              // estimated treatment effects
  array[J] real<lower=0> sigma; // standard error of effect estimates
}
parameters {
  real mu;                // population treatment effect
  real<lower=0> tau;      // standard deviation in treatment effects
  vector[J] eta;          // unscaled deviation from mu by school
}
transformed parameters {
  vector[J] theta = mu + tau * eta;        // school treatment effects
}
model {
  target += normal_lpdf(eta | 0, 1);       // prior log-density
  target += normal_lpdf(y | theta, sigma); // log-likelihood
}
"""

schools_data = {"J": 8,
                "y": [28,  8, -3,  7, -1,  1, 18, 12],
                "sigma": [15, 10, 16, 11,  9, 11, 10, 18]}


# Build the model
model = stan.build(schools_code, data=schools_data, random_seed=1)

# Assuming `model` is the compiled Stan model
# and `param` is a dictionary of your parameters:
param = {
    "mu": 0,    # Example value for mu
    "tau": 1,   # Example value for tau
    "eta": [0, 0, 0, 0, 0, 0, 0, 0]  # Example values for eta
}

# Convert your parameter dictionary to a list in the order expected by your model
# For simplicity, this example assumes eta is already a list. Adjust as necessary.
param_list = [param["mu"], param["tau"]] + param["eta"]

# Compute the gradient
gradient = model.grad_log_prob(param_list)

print("Gradient:", gradient)