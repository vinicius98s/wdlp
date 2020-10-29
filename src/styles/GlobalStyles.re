open Css;

let add = () => {
  global("*", [
    margin(zero),
    padding(zero),
    boxSizing(borderBox),
    fontFamilies([`custom("Roboto"), `sansSerif]),
  ]);
};
