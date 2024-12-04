// create a URL constant to store the URL being queried
const URL = "https://pokeapi.co/api/v2/pokemon/";
//declare an asynchronous function to make the api call (must be declared async to use async logic). An async function function 
//returns a Promise. 
async function getAPokemon(pokemon) {
  try {
    //await causes the program to pause execution until the function fetch() is resolved. 
    //If we did not use await, the program would continue before resolution and response would be a Promise object. Later, when the
    //program attempted to access the values of the response we expected, we would be given a value of undefined. 
    //fetch(), as described in the documentation, returns a response object. https://developer.mozilla.org/en-US/docs/Web/API/Fetch_API
    const response = await fetch(URL + pokemon);
    //.ok is a property of the response object that indicates whether the api call was successful by checking the response status code
    //is in the range of numbers representing success. Status codes are standardized by the HTTP protocol
    if (!response.ok) {
      //throws an error that tells us the response code (which will indicate the nature of the failure) if the response is unsuccessful
      throw new Error(`status: ${response.status}`);
    }
    //if the response was successful, we can use the .json() method of the response object to convert the body ofthe response to JSON 
    //format, whereas it will initially be a stream of text.
    // we use the await keyword to trigger the program to pause until the parsing is done because, again, 
    //it will otherwise assign a Promise to the data variable, whose values will be undefined when we try to access it prematurely 
    const data = await response.json();
    //the function now returns that json object
    return data;
  } catch (error) {
    //catch any errors and display the error in the console, return null to indicate there was an issue
    console.error("Error:", error);
    return null;
  }
}

//the api call is made in another asynchronous function to ensure the response is fully resolved before we
//attempt to use it in the assignment statement. If the function is not declared asynchronous, the outer function 
//won't wait for the inner function to resolve, and the pikachu variable will be undefined. 
async function main() {
  const pikachu = await getAPokemon("pikachu");
  console.log(pikachu);
}

//invoke main to demo the api call. Results will be printed to the console. 
main();
