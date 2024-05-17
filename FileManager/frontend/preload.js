const { contextBridge, ipcRenderer } = require('electron/renderer')

contextBridge.exposeInMainWorld('electronAPI', {
  listFiles: (directory) => ipcRenderer.invoke('listFiles', directory)
})