#pragma once

#include <vector>
#include <map>

namespace ppc {

	//IF ADDING A JOB IT MUST BE PRESENT IN ALL LISTS OR THERE WILL BE
	//PROBLEMS
	const std::vector<std::string> JOBS_ALL = {
		"Retail Sales Associate",
		"Retail General Manager",
		"Office Clerk",
		"Chef",
		"Line Cook",
		"Nurse",
		"Waitstaff",
		"Customer Service",
		"Janitor",
		"Teacher",
		"Manual Laborer",
		"Secretary",
		"Truck Driver",
		"Sales",
		"Mechanic",
		"Administrative Assistant",
		"Security Guard",
		/*"Factory Worker",
		"Housekeeping",
		"Food Preparation",
		"Landscaping",
		"Construction",
		"Doctor",
		"Lawyer",
		"Student",
		"Police Officer",
		"Firefighter",
		"Software Engineer",
		"Computer Engineer",
		"System Administrator",
		"Bartender",
		"Child Care",
		"Bank Teller",
		"Accountant",
		"Electrician",
		"Dishwasher",
		"Bus Driver",
		"Plumber",
		"Taxi Driver",
		"Cosmetologist"*/
	};

	const std::map<std::string, int> STARTING_INCOME_MAP = {
		{"Retail Sales Associate", 16 },
		{"Retail General Manager", 29 },
		{"Office Clerk", 20 },
		{"Chef", 40 },
		{"Line Cook", 18 },
		{"Nurse", 39},
		{"Waitstaff", 12 },
		{"Customer Service", 25},
		{"Janitor", 14 },
		{"Teacher", 32 },
		{"Manual Laborer", 19 },
		{"Secretary", 19 },
		{"Truck Driver", 30 },
		{"Sales", 23 },
		{"Mechanic", 24 },
		{"Administrative Assistant", 26 },
		{"Security Guard", 20 },
		/* {"Factory Worker", },
		{"Housekeeping", },
		{"Food Preparation", },
		{"Landscaping", },
		{"Construction", },
		{"Doctor", },
		{"Lawyer", },
		{"Student", },
		{"Police Officer", },
		{"Firefighter", },
		{"Software Engineer", },
		{"Computer Engineer", },
		{"System Administrator", },
		{"Bartender", },
		{"Child Care", },
		{"Bank Teller", },
		{"Accountant", },
		{"Electrician", },
		{"Dishwasher", },
		{"Bus Driver", },
		{"Plumber", },
		{"Taxi Driver", },
		{"Cosmetologist", } */
	};

	const std::map<std::string, int> MEDIAN_INCOME_MAP = {
		{ "Retail Sales Associate", 35 },
		{ "Retail General Manager", 45 },
		{ "Office Clerk", 29 },
		{ "Chef", 56 },
		{ "Line Cook", 27 },
		{ "Nurse", 58 },
		{ "Waitstaff", 25 },
		{ "Customer Service", 32 },
		{ "Janitor", 23 },
		{ "Teacher", 46 },
		{ "Manual Laborer", 34 },
		{ "Secretary", 30 },
		{ "Truck Driver", 49 },
		{ "Sales", 40 },
		{ "Mechanic", 42 },
		{ "Administrative Assistant", 37 },
		{ "Security Guard", 29 },
		/* { "Factory Worker", },
		{ "Housekeeping", },
		{ "Food Preparation", },
		{ "Landscaping", },
		{ "Construction", },
		{ "Doctor", },
		{ "Lawyer", },
		{ "Student", },
		{ "Police Officer", },
		{ "Firefighter", },
		{ "Software Engineer", },
		{ "Computer Engineer", },
		{ "System Administrator", },
		{ "Bartender", },
		{ "Child Care", },
		{ "Bank Teller", },
		{ "Accountant", },
		{ "Electrician", },
		{ "Dishwasher", },
		{ "Bus Driver", },
		{ "Plumber", },
		{ "Taxi Driver", },
		{ "Cosmetologist", } */
	};

	const std::map<std::string, bool> INCOME_CAP = {
		{ "Retail Sales Associate", true },
		{ "Retail General Manager", true },
		{ "Office Clerk", true },
		{ "Chef", false },
		{ "Line Cook", true },
		{ "Nurse", false },
		{ "Waitstaff", true },
		{ "Customer Service", true },
		{ "Janitor", true },
		{ "Teacher", false },
		{ "Manual Laborer", false },
		{ "Secretary", false },
		{ "Truck Driver", false },
		{ "Sales", false },
		{ "Mechanic", true },
		{ "Administrative Assistant", true },
		{ "Security Guard", true },
		/*{ "Factory Worker", },
		{ "Housekeeping", },
		{ "Food Preparation", },
		{ "Landscaping", },
		{ "Construction", },
		{ "Doctor", },
		{ "Lawyer", },
		{ "Student", },
		{ "Police Officer", },
		{ "Firefighter", },
		{ "Software Engineer", },
		{ "Computer Engineer", },
		{ "System Administrator", },
		{ "Bartender", },
		{ "Child Care", },
		{ "Bank Teller", },
		{ "Accountant", },
		{ "Electrician", },
		{ "Dishwasher", },
		{ "Bus Driver", },
		{ "Plumber", },
		{ "Taxi Driver", },
		{ "Cosmetologist", }*/
	};

	/*
	whoops probably unnecessary

	const std::vector<std::string> JOBS_0 = {
		"Retail Sales Associate",
		"Retail General Manager",
		"Chef",
		"Line Cook",
		"Waitstaff",
		"Customer Service",
		"Janitor",
		"Manual Laborer",
		"Security Guard",
		"Truck Driver" ,
	};

	const std::vector<std::string> JOBS_1 = {
		"Office Clerk",
		"Secretary",
		"Sales",
		"Mechanic",
		"Administrative Assistant",
	};

	const std::vector<std::string> JOBS_2 = {
		
	};

	const std::vector<std::string> JOBS_3 = {
		"Teacher"
	};

	const std::vector<std::string> JOBS_4 = {

	}
	*/

	// 0 - DID NOT GRADUATE HIGH SCHOOL, 1 - HIGH SCHOOL GRADUATE
	// 2 - ASSOCIATE DEGREE, 3 - BACHELORS DEGREE, 
	// 4 - MASTERS DEGREE, 5 - DOCTORATE
	const std::map<std::string, int> MIN_EDUCATION = {
		{ "Retail Sales Associate", 0 },
		{ "Retail General Manager", 0 },
		{ "Office Clerk", 1 },
		{ "Chef", 0 },
		{ "Line Cook", 0 },
		{ "Nurse", 4 },
		{ "Waitstaff", 0 },
		{ "Customer Service", 0 },
		{ "Janitor", 0 },
		{ "Teacher", 3 },
		{ "Manual Laborer", 0 },
		{ "Secretary", 1 },
		{ "Truck Driver", 0 },
		{ "Sales", 1 },
		{ "Mechanic", 1 },
		{ "Administrative Assistant", 1 },
		{ "Security Guard", 0 },
		/* {"Factory Worker", },
		{"Housekeeping", },
		{"Food Preparation", },
		{"Landscaping", },
		{"Construction", },
		{"Doctor", },
		{"Lawyer", },
		{"Student", },
		{"Police Officer", },
		{"Firefighter", },
		{"Software Engineer", },
		{"Computer Engineer", },
		{"System Administrator", },
		{"Bartender", },
		{"Child Care", },
		{"Bank Teller", },
		{"Accountant", },
		{"Electrician", },
		{"Dishwasher", },
		{"Bus Driver", },
		{"Plumber", },
		{"Taxi Driver", },
		{"Cosmetologist", } */
	};

};