let _assign = Js.Obj.assign;
type preactComponent;
type preactInput;

type preactElement;
type preactOutput = (. unit) => preactElement;

let factory: (preactComponent, preactInput) => preactOutput = [%bs.raw
  {|
    function(Constructor, PreactComponent) {
        var P = class extends Constructor {};
        P.prototype = _assign(
            P.prototype,
            PreactComponent,
        );
        return P;
    }
|}
];

[@bs.module "preact"] external preactComponent: preactComponent = "Component";

[@bs.new] external makeClass: 

let createClass = factory(preactComponent);

[@bs.module "preact"]
external render: (preactElement, Dom.element) => unit = "render";