var elm = require('elm');
var icons = require('icons');

var window = elm.realise(elm.Window({
  title: 'Gengrid',
  width: 480,
  height: 480,
  elements: {
    background: elm.Background({
      expand: 'both',
      fill: 'both',
      resize: true
    }),
    box: elm.Box({
      expand: 'both',
      fill: 'both',
      resize: true,
      elements: {
        grid: elm.Gengrid({
          expand: 'both',
          fill: 'both',
          elements: {}
        })
      }
    })
  }
}));

var gengrid_item = function(image) {
  return {
    data: image,
    'class' : {
      style: 'default',
      text: function(part) {
        return this.data;
      },
      content: function(part) {
        if (part == 'elm.swallow.icon')
          return elm.Icon({ lookup_order: 'fdo,theme', image: this.data });
      },
      state: function(part) {
        return false
      }
    },
    on_select: function(item) {
      print("Selected " + this.data + " icon.");
    }
  };
};

var grid_elements = window.elements.box.elements.grid.elements;

for (var i = 0; i < icons.elementary.length; ++i)
  grid_elements[i] = gengrid_item(icons.elementary[i]);

for (var i = icons.elementary.length; i < icons.freedesktop.length; ++i)
  grid_elements[i] = gengrid_item(icons.freedesktop[i]);
