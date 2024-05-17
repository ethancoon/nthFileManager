const { app, BrowserWindow, ipcMain, dialog } = require('electron/main')
const path = require('node:path')
const addon = require('./build/Release/addon');
const fs = require('fs');

// Function to retrieve list of files in a directory
function getFilesInDirectory(dirPath = "/") {
    return fs.readdirSync(dirPath);
}


function createWindow () {
  const mainWindow = new BrowserWindow({
    webPreferences: {
      preload: path.join(__dirname, 'preload.js')
    }
  })
  mainWindow.loadFile('index.html')
}

app.whenReady().then(() => {
  ipcMain.handle('listFiles', (event, directory) => {
    return getFilesInDirectory(directory);
  });
  createWindow()
  app.on('activate', function () {
    if (BrowserWindow.getAllWindows().length === 0) createWindow()
  })
})

app.on('window-all-closed', function () {
  if (process.platform !== 'darwin') app.quit()
})