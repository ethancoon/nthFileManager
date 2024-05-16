const { contextBridge, ipcRenderer } = require('electron/renderer')

contextBridge.exposeInMainWorld('electronAPI', {
  listFiles: () => ipcRenderer.invoke('listFiles')
})