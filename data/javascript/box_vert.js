#!/usr/local/bin/elev8

var EXPAND_BOTH = { x : 1.0, y : 1.0 };
var FILL_BOTH = { x : -1.0, y : -1.0 };

var elements = {
	the_background : {
		type : "background",
		weight : EXPAND_BOTH,
	},
	pack_box : {
		type : "pack",
		weight : EXPAND_BOTH,
		elements : {
			logo_top : {
				type : "icon",
				image : "data/images/logo_small.png",
				scale : { x : false, y : false },
				align : { x : 0.5, y : 0.5 },
			},
			logo_middle : {
				type : "icon",
				image : "data/images/logo_small.png",
				scale : { x : false, y : false },
				align : { x : 0.0, y : 0.5 },
			},
			logo_bottom : {
				type : "icon",
				image : "data/images/logo_small.png",
				scale : { x : false, y : false },
				align : { x : 1.0, y : 0.5 },
			},
		},
	},
};