#include "SolutionMethod.h"


SolutionMethod::SolutionMethod() : iteration_(0), iterationOfBestSolution_(0), 
elapsedTime_(0), elapsedTimeOfBestSolution_(0), stopCriterion_() {}


SolutionMethod::~SolutionMethod(){}

//Solution& SolutionMethod::getBestSolution() { return *bestSolution_; }

//Problem& SolutionMethod::getProblem() { return *problem_; }

int SolutionMethod::getIteration() { return iteration_; }

int SolutionMethod::getIterationOfBestSolution() { return iterationOfBestSolution_; }

double SolutionMethod::getElapsedTime() { return elapsedTime_; }

double SolutionMethod::getElapsedTimeOfBestSolution() { return elapsedTimeOfBestSolution_; }

StopCriterion SolutionMethod::getStopCriterion() { return stopCriterion_; }

void SolutionMethod::setStopCriterion(StopCriterion criterion) { stopCriterion_ = criterion; }

//void SolutionMethod::setBestSolution(Solution& solution) { bestSolution_ = &solution; }

//void SolutionMethod::setProblem(Problem& problem) { problem_= &problem; }

void SolutionMethod::resetIteration() { iteration_ = 0; }

void  SolutionMethod::resetElapsedTime() { elapsedTime_ = 0; }

void  SolutionMethod::runSearch() {}

void  SolutionMethod::setIteration(int iteration) { iteration_ = iteration; }

void  SolutionMethod::increaseIteration() { iteration_++; }

void SolutionMethod::setIterationOfBestSolution(int iteration) { iterationOfBestSolution_ = iteration; }

void SolutionMethod::setElapsedTimeOfBestSolution(double time) { elapsedTimeOfBestSolution_ = time; }