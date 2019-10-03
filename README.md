# addon  node-gyp 사용

순서대로
npm install --global --production windows-build-tools
npm config set python 2.7
node-gyp configure
node-gyp build
node index.js
