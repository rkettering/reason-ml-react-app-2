
type state = {
  canvasRef: ref(option(Dom.element))
};



let setCanvasRef = (theRef, {ReasonReact.state}) => {
	state.canvasRef := Js.Nullable.toOption(theRef);
};

let component = ReasonReact.reducerComponent("CanvasThing");


let make = (_children) => {
	let handleClick = (_event, self) => {
			Js.log(self.state);
		/*switch (self.state.canvasRef^) {
		|	None => ()
		|	Some(r) => self.state.canvasRef.fillRect( Canvas.getContext( self.state.canvasRef, "2d"), 0.0, 0.0, 100, 100);
	}*/

	};

	{
	...component,
	initialState: () => {
    	{canvasRef: ref(None)}
    },
	reducer: ((), _) => ReasonReact.NoUpdate,
	render: self =>
		<div onClick=(self.handle(handleClick))>
			<canvas
				width="100"
				height="100"
				ref={self.handle(setCanvasRef)}
			/>
		</div>,
	}
};
