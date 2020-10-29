open Css;

module Colors = {
  let blue = variant => {
    switch (variant) {
    | `primary => hex("02AAF1")
    | `darker => hex("243278")
    };
  };

  let white = hex("FFFFFF");

  let grey = hex("616161");
};
