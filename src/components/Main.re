open Css;
open Theme;

let s = React.string;

[@react.component]
let make = () => {
  let defaultBreakpoint = 1020;
  let defaultMedia = (styles, ~min=true, ()) => {
    let widthVariant = min ? "(min-width: " : "(max-width: ";

    media(widthVariant ++ defaultBreakpoint->string_of_int ++ "px)", styles);
  };

  let container =
    style([
      display(flexBox),
      alignItems(center),
      justifyContent(center),
      defaultMedia([flexDirection(column)], ~min=false, ()),
    ]);

  let title =
    style([
      fontWeight(`num(900)),
      fontSize(px(19)),
      color(Colors.blue(`darker)),
      lineHeight(px(22)),
      defaultMedia([fontSize(px(38)), lineHeight(px(49))], ()),
    ]);

  let description =
    style([
      fontWeight(`num(400)),
      fontSize(px(14)),
      lineHeight(px(16)),
      color(Colors.grey),
      marginTop(px(10)),
      defaultMedia([fontSize(px(20)), lineHeight(pxFloat(35.16))], ()),
    ]);

  let textWrapper =
    style([
      maxWidth(px(705)),
      marginRight(px(30)),
      defaultMedia(
        [maxWidth(vw(100.)), marginRight(zero)],
        ~min=false,
        (),
      ),
    ]);

  let phoneMock =
    style([
      zIndex(1),
      defaultMedia([marginTop(px(50))], ~min=false, ()),
    ]);

  <div className=container>
    <div className=textWrapper>
      <h1 className=title>
        {j|COM O WEDEAL VOCÊ REINVENTA O SEU JEITO DE NEGOCIAR & TRABALHAR|j}
        ->s
      </h1>
      <p className=description>
        {j|Monte e participe de equipes; Venda suas ideias e invista em projetos de forma fácil, online e menos burocrática.|j}
        ->s
      </p>
      <Button
        bgColor={Colors.blue(`primary)}
        styles={style([marginTop(px(14))])}>
        {"Entrar para wedeal"->String.uppercase_ascii->s}
      </Button>
    </div>
    <img
      width="214"
      height="431"
      className=phoneMock
      src="/assets/phone-mock.png"
      alt=""
    />
  </div>;
};
