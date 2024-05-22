const btn = document.getElementById('btn')
const fileListElement = document.getElementById('fileList')
const filePathInput = document.getElementById('filePathInput')

btn.addEventListener('click', async () => {
  const filePath = filePathInput.value;
  const files = await window.electronAPI.listFiles(filePath);
  fileListElement.innerHTML = ''; // Clear previous list
  files.forEach(file => {
    const li = document.createElement('li');
    li.textContent = file;
    fileListElement.appendChild(li);
  });
});

window.addEventListener('DOMContentLoaded', async () => {
  const rootDirectoryFiles = await window.electronAPI.listFiles('/');
  rootDirectoryFiles.forEach(file => {
    const li = document.createElement('li');
    li.textContent = file;
    fileListElement.appendChild(li);
  });
});