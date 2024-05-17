const btn = document.getElementById('btn')
const fileListElement = document.getElementById('fileList')

window.addEventListener('DOMContentLoaded', async () => {
  const files = await window.electronAPI.listFiles();
  files.forEach(file => {
    const li = document.createElement('li');
    li.textContent = file;
    fileListElement.appendChild(li);
  });
});