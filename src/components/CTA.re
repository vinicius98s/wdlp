open Css;
open Theme;

let uppercaseText = s => s |> Js.String.toUpperCase |> React.string;

let defaultValue = (v: option('a), d) => {
  switch (v) {
  | Some(value) => value
  | None => d
  };
};

module ShowCase = {
  [@react.component]
  let make = (~title, ~description, ~children=?, ~invert=?, ~styles=?, ()) => {
    let shouldInvert = defaultValue(invert, false);
    let additionalStyles = defaultValue(styles, "");

    let wrapper =
      style([
        display(flexBox),
        flexDirection(shouldInvert ? rowReverse : row),
        alignItems(center),
      ]);

    let textWrapper =
      style([
        before([
          contentRule(`text("")),
          background(Colors.blue(`primary)),
          display(block),
          width(px(83)),
          height(px(5)),
          borderRadius(px(16)),
          minWidth(px(130)),
          marginBottom(px(10)),
        ]),
      ]);

    let titleStyles =
      style([
        color(Colors.blue(`darker)),
        fontSize(px(17)),
        fontWeight(`num(700)),
        media("(min-width: 1050px)", [
          fontSize(px(48)),
          lineHeight(pxFloat(56.25))
        ]),
      ]);

    let descriptionStyles =
      style([
        color(hex("9E9E9E")),
        marginTop(px(20)),
        fontWeight(`num(300)),
        fontSize(px(13)),
        media("(min-width: 1050px)", [
          fontSize(px(40)),
          lineHeight(pxFloat(46.88))
        ]),
      ]);

    <div className={Css.merge([wrapper, additionalStyles])}>
      <div className=textWrapper>
        <h1 className=titleStyles> title </h1>
        <p className=descriptionStyles> description->React.string </p>
      </div>
      {switch (children) {
       | Some(c) => c
       | None => React.null
       }}
    </div>;
  };
};

module Pictures = {
  [@react.component]
  let make = () => {
    let base =
      style([
        position(absolute),
        width(px(300)),
        media("(max-width: 900px)", [width(px(150))]),
      ]);

    <div className={style([height(px(600)), position(relative)])}>
      <img
        className={Css.merge([base, style([left(px(-20))])])}
        src="/assets/sketch.png"
      />
      <img
        className={Css.merge([
          base,
          style([
            left(vw(26.)),
            bottom(px(80)),
            width(px(350)),
            media("(max-width: 900px)", [bottom(px(180))]),
          ]),
        ])}
        src="/assets/code.png"
      />
      <img
        className={Css.merge([
          base,
          style([
            right(vw(16.)),
            media("(max-width: 900px)", [right(vw(1.)), top(px(20))]),
          ]),
        ])}
        src="/assets/notes.png"
      />
      <img
        className={Css.merge([
          base,
          style([
            bottom(zero),
            right(vw(0.)),
            media("(max-width: 900px)", [right(vw(2.))]),
          ]),
        ])}
        src="/assets/design.png"
      />
    </div>;
  };
};

[@react.component]
let make = () => {
  let container =
    style([
      background(Colors.blue(`darker)),
      width(`calc((`add, pct(100.), px(40)))),
      margin2(~h=px(-20), ~v=zero),
      marginTop(px(50)),
      padding2(~v=zero, ~h=px(40)),
      textAlign(center),
      height(px(140)),
      display(flexBox),
      alignItems(center),
      justifyContent(center),
      media("(min-width: 1050px)", [height(px(500))]),
    ]);

  let text =
    style([
      color(Colors.white),
      fontSize(px(45)),
      lineHeight(pxFloat(52.73)),
      fontWeight(`num(700)),
      media("(max-width: 1050px)", [
        fontSize(px(17)),
        lineHeight(pxFloat(19.92))
      ]),
    ]);

  let desktopImg = style([width(pct(100.))]);

  <>
    <div className=container>
      <h1 className=text>
        {j|Faça parte de equipes e desenvolva projetos incríveis para variados clientes.|j}
        ->uppercaseText
      </h1>
    </div>
    <ShowCase
      title={{j|Mostre o seu potencial!|j}->uppercaseText}
      description="Fidelize aquele cliente dos sonhos mostrando o seu melhor nos projetos que participa."
      styles={style([
        marginTop(px(-100)),
        media("(max-width: 1050px)", [marginTop(px(0))]),
      ])}>
      <img
        className={style([width(pct(50.)), marginRight(px(-20))])}
        src="/assets/app-screens.png"
        alt=""
      />
    </ShowCase>
    <ShowCase
      title={{j|Faça acontecer!|j}->uppercaseText}
      invert=true
      description={j|Divulgue suas ideias de forma segura para investidores, monte equipe com profissionais qualificados cadastrados na plataforma e administre o desenvolvimento do projeto do começo ao fim.|j}
      styles={style([media("(max-width: 1050px)", [marginTop(px(30))])])}>
      <img
        className={style([width(pct(35.))])}
        src="/assets/screen-app-mock.png"
        alt=""
      />
    </ShowCase>
    <Pictures />
    <ShowCase
      title={{j|Criatividade à espera de uma oportunidade|j}->uppercaseText}
      description={j|Com a WeDeal você tem acesso a um vasto banco de ideias fora da caixa esperando algum tipo de investimento ou mão de obra qualificada para serem desenvolvidos e entregues ao mundo.|j}
      styles={style([width(pct(100.)), maxWidth(px(800))])}
    />
    <img className=desktopImg src="/assets/wedeal-desktop.png" />
    <ShowCase
      title={{j|A melhor parte!|j}->uppercaseText}
      description={j|Estipule quanto vale os seus serviços; e escolha os dias e a carga horária em que deseja trabalhar.|j}
      styles={style([width(pct(100.)), maxWidth(px(1200)), marginBottom(px(70))])}
    />
  </>;
};
