var os = require("os");

let repo = "https://github.com/florinxfl/florin-core/releases/download/development/";

let file = "";

if (os.platform() === "win32") {
  file = "libflorin_win_" + os.arch() + ".node";
} else if (os.platform() === "linux") {
  file = "libflorin_linux_" + os.arch() + ".node";
} else if (os.platform() === "darwin") {
  console.log(os.arch(), "os.arch()");
  file = "libflorin_macos_" + os.arch() + ".node";
} else {
  throw "Unable to determine platform";
}

const fs = require("fs");
const request = require("request");
let error;
const download = (uri, filename) => {
  request(uri)
    .on("error", err => {
      error = err;
    })
    .on("response", response => {
      if (response.statusCode !== 200) {
        error = `error downloading ${uri} : ${response.statusCode}`;
      } else {
        console.log(`downloading ${uri}...`);
      }
    })
    .pipe(fs.createWriteStream(filename))
    .on("close", () => {
      if (error !== undefined) console.error(error);
      else console.log(`fetched ${src} -> ${dst}`);
    });
};

const path = require("path");
let src = repo + file;
console.log(src, "src");
let dst = path.join(__dirname, `../src/unity/lib_unity.node`);
download(src, dst);
