open Css;
open Theme;

[@react.component]
let make = () => {
  let container =
    style([
      background(Colors.blue(`darker)),
      width(vw(100.)),
      margin2(~h=px(-20), ~v=zero),
      marginTop(px(50)),
      padding2(~v=zero, ~h=px(40)),
      textAlign(center),
      height(px(140)),
      display(flexBox),
      alignItems(center),
    ]);

  let text =
    style([
      color(Colors.white),
      fontSize(px(17)),
      fontWeight(`num(700)),
    ]);

  <div className=container>
    <h1 className=text>
      {{j|Faça parte de equipes e desenvolva projetos incríveis para variados clientes.|j}
       |> Js.String.toUpperCase
       |> React.string}
    </h1>
  </div>;
};
