[@bs.val] [@bs.scope "document"]
external getElementById: string => Dom.element = "getElementById";

let test = Preact.createClass({pub render = () => "xxx"}->Obj.magic);
Js.log(test);
let e = test(.);
Js.log(e);

Preact.render(e, getElementById("app"));