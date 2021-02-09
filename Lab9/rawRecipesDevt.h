//
// input recipe list from https://www.allrecipes.com/recipes/15103/salad/vegetable-salads/broccoli-salad
// In this array recipe titles are prefixed with a 0 and these are followed by ingredients, all of which
// are prefixed with a 1. So the first recipe is "Broccoli Coleslaw" which has ingredients "olive oil",
// "white vinegar",...,"sunflower seeds". The second recipe is "Creamy Broccoli Salad".
// The prefixes should not be printed out and can be stripped off the strings if that is convenient to you.
// The list ends with an empty string as terminator
//
char *rawRecipes[]={
"0Broccoli Coleslaw",
"1olive oil",
"1white vinegar",
"1broccoli",
"0Creamy Broccoli Salad",
"1broccoli",
"1white sugar",
"1red onion",
"1white wine vinegar",
"0Minnesota Broccoli Salad",
"1eggs",
"1broccoli",
"1red onion",
""
};