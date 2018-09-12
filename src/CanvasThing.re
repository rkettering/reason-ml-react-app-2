
type state = {
  canvasRef: ref(option(Dom.element))
};


let component = ReasonReact.reducerComponent("CanvasThing");


let make = (_children) => {
	let handleClick = (_event, self: ReasonReact.self(state, ReasonReact.noRetainedProps, unit)) => {
		Js.log(self.state);
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
			/>
		</div>,
	}
};
