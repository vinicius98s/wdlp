open Css;
open Theme;

[@react.component]
let make = () => {
  let wrapper =
    style([
      width(vw(99.)),
      background(Colors.blue(`primary)),
      overflowY(hidden),
      height(vw(50.)),
      color(Colors.white),
      display(flexBox),
      alignItems(center),
      justifyContent(center),
      flexDirection(column),
      borderTopLeftRadius(vw(50.)),
      borderTopRightRadius(vw(50.)),
      marginTop(px(30)),
      media(
        "(max-width: 700px)",
        [
          selector("h1", [fontSize(px(18)), paddingTop(px(30))]),
          selector(
            "button",
            [width(pct(40.)), fontSize(px(12)), height(px(35))],
          ),
        ],
      ),
      media(
        "(max-width: 460px)",
        [
          selector("h1", [paddingTop(px(40))]),
          selector(
            "button",
            [width(pct(40.)), fontSize(px(10)), height(px(35))],
          ),
        ],
      ),
    ]);

  <footer className=wrapper>
    <h1 className={style([marginTop(auto)])}>
      "SE REIVENTE COM WEDEAL!"->React.string
    </h1>
    <Button
      bgColor={Colors.blue(`darker)}
      styles={style([
        marginTop(px(20)),
        width(pct(30.)),
        height(px(50)),
      ])}>
      {"Entrar para wedeal"->String.uppercase_ascii->React.string}
    </Button>
    <p className={style([marginTop(auto)])}> "WeDeal 2020"->React.string </p>
    <p className={style([marginBottom(px(20))])}>
      "Todos os direitos reservados"->React.string
    </p>
  </footer>;
};
