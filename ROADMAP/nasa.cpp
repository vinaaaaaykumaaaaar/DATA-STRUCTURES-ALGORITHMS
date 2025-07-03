#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>

/**
 * @brief NASA-style documentation for spacecraft trajectory calculation.
 *
 * This class simulates the navigation system for a spacecraft traveling from Earth to Mars.
 * It considers acceleration, coasting, and deceleration phases and provides the spacecraft's
 * position and velocity at each time step.
 */

class Spacecraft
{
public:
    /**
     * @brief Constructor to initialize spacecraft properties.
     * @param initial_velocity The spacecraft's initial velocity in km/s.
     * @param fuel_mass The spacecraft's fuel mass in kg.
     * @param thrust The spacecraft's thrust in Newtons.
     * @param distance_to_mars Distance to Mars in kilometers.
     */
    Spacecraft(double initial_velocity, double fuel_mass, double thrust, double distance_to_mars);

    /**
     * @brief Calculates the spacecraft's position at a given time.
     * @param time Time since launch in seconds.
     * @return Current position in kilometers.
     */
    double calculatePosition(double time);

    /**
     * @brief Calculates the spacecraft's velocity at a given time.
     * @param time Time since launch in seconds.
     * @return Current velocity in km/s.
     */
    double calculateVelocity(double time);

    /**
     * @brief Runs the simulation from Earth to Mars.
     * @param time_step The time step for the simulation in seconds.
     * @return A vector containing position and velocity at each time step.
     */
    std::vector<std::pair<double, double>> runSimulation(double time_step);

private:
    double initial_velocity_;           // Spacecraft's initial velocity in km/s
    double fuel_mass_;                  // Fuel mass in kg
    double thrust_;                     // Thrust in Newtons
    double distance_to_mars_;           // Distance to Mars in kilometers
    double gravitational_acceleration_; // Gravitational acceleration constant

    /**
     * @brief Calculates the acceleration of the spacecraft based on thrust and mass.
     * @return Acceleration in m/s^2.
     */
    double calculateAcceleration();

    /**
     * @brief Safely handles any simulation errors such as division by zero.
     * @param message The error message to display.
     */
    void handleError(const std::string &message);
};

// Implementation

Spacecraft::Spacecraft(double initial_velocity, double fuel_mass, double thrust, double distance_to_mars)
    : initial_velocity_(initial_velocity),
      fuel_mass_(fuel_mass),
      thrust_(thrust),
      distance_to_mars_(distance_to_mars),
      gravitational_acceleration_(9.81) // Earth's gravity constant
{
    if (fuel_mass_ <= 0 || thrust_ <= 0 || distance_to_mars_ <= 0)
    {
        handleError("Invalid input: Fuel mass, thrust, and distance to Mars must be positive values.");
    }
}

double Spacecraft::calculateAcceleration()
{
    // Using a simplified version of Newton's second law: a = F / m
    return thrust_ / fuel_mass_;
}

double Spacecraft::calculatePosition(double time)
{
    double acceleration = calculateAcceleration();
    // Simple physics formula: s = ut + 0.5 * at^2
    return (initial_velocity_ * time) + (0.5 * acceleration * std::pow(time, 2));
}

double Spacecraft::calculateVelocity(double time)
{
    double acceleration = calculateAcceleration();
    // Simple physics formula: v = u + at
    return initial_velocity_ + (acceleration * time);
}

std::vector<std::pair<double, double>> Spacecraft::runSimulation(double time_step)
{
    std::vector<std::pair<double, double>> trajectory;
    double time = 0;
    double position = 0;

    while (position < distance_to_mars_)
    {
        double velocity = calculateVelocity(time);
        position = calculatePosition(time);
        trajectory.push_back(std::make_pair(position, velocity));
        time += time_step;
    }
    return trajectory;
}

void Spacecraft::handleError(const std::string &message)
{
    std::cerr << "Error: " << message << std::endl;
    throw std::runtime_error(message);
}

int main()
{
    try
    {
        // Initializing the spacecraft with parameters
        Spacecraft spacecraft(0.0, 2000000.0, 35000.0, 225000000.0); // Initial velocity, fuel mass, thrust, distance to Mars

        // Running the simulation with a time step of 1000 seconds
        std::vector<std::pair<double, double>> trajectory = spacecraft.runSimulation(1000.0);

        // Output the simulation results
        for (const auto &step : trajectory)
        {
            std::cout << "Position: " << step.first << " km, "
                      << "Velocity: " << step.second << " km/s" << std::endl;
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Simulation failed: " << e.what() << std::endl;
    }

    return 0;
}
