const btn = document.getElementById('btn')
const filePathElement = document.getElementById('filePath')

btn.addEventListener('click', async () => {
  const files = await window.electronAPI.listFiles()
  filePathElement.innerText = files
})