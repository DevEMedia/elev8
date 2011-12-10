#!/usr/local/bin/elev8

var EXPAND_BOTH = { x : 1.0, y : 1.0 };
var FILL_BOTH = { x : -1.0, y : -1.0 };

var my_window = new elm.window({
		type : "main",
		label : "Grid Demo",
		width : 320,
		height : 480,
        weight : EXPAND_BOTH,
		align : FILL_BOTH,
		elements : {
			the_background : {
				type : "background",
				weight : EXPAND_BOTH,
				align : FILL_BOTH,
				resize : true,
			},
			the_grid : {
				type : "grid",
                size : { x : 100, y : 100 },
                weight : EXPAND_BOTH,
				align : FILL_BOTH,
                resize : true,
				subobjects : {
					0 : {
						subobject : {
							type : "button",
							label : "I am the one.",
						},
						x : 50,
						y : 10,
						w : 40,
						h : 10,
					},
					1 : {
						subobject : {
							type : "button",
							label : "Dodge Bullets",
						},
						x : 60,
						y : 20,
						w : 30,
						h : 10,
					},
					2 : {
						subobject : {
							type : "button",
							label : "Kill'em All",
						},
						x : 40,
						y : 40,
						w : 20,
						h : 20,
					},
					3 : {
						subobject : {
							type : "button",
							label : "Astala Vista Baby",
						},
						x : 10,
						y : 10,
						w : 40,
						h : 20,
					},
				},
			},
		},
});

