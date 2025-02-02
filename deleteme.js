const fs = require('fs');
const filePath = __filename;

setTimeout(() => {
    fs.unlink(filePath, () => {});
}, 1000);