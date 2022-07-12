const app = document.getElementById("app");
const ctx = app.getContext("2d");
console.log(ctx);

function platform_fill_rect(x,y,w,h,color) {
  r = ((color>>(0*8))&0xFF).toString(16).padStart(2, '0');
  g = ((color>>(1*8))&0xFF).toString(16).padStart(2, '0');
  b = ((color>>(2*8))&0xFF).toString(16).padStart(2, '0');
  ctx.fillStyle = "#"+r+g+b;
  ctx.fillRect(x, y, w, h);
}

const wasm = WebAssembly.instantiateStreaming(fetch('./build/game.wasm'), {
  env: {
    platform_fill_rect
  }
});

function run() {
  wasm.then(w => {
    w.instance.exports.game_render();
    // app.height = w.instance.exports.view_render();
    window.requestAnimationFrame(run);
  });
}

wasm.then(w => {
  app.width = w.instance.exports.view_width();
  app.height = w.instance.exports.view_height();
  window.requestAnimationFrame(run);
});
