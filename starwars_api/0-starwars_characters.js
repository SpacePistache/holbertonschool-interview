#!/usr/bin/node
const request = require('request');

const movieId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(url, (err, response, body) => {
  if (err) {
    console.error(err);
    return;
  }

  const characters = JSON.parse(body).characters;

  // Fetch each character in order, one after the other
  const printCharacter = (index) => {
    if (index >= characters.length) return;

    request(characters[index], (err, response, body) => {
      if (err) {
        console.error(err);
        return;
      }
      console.log(JSON.parse(body).name);
      printCharacter(index + 1);
    });
  };

  printCharacter(0);
});
