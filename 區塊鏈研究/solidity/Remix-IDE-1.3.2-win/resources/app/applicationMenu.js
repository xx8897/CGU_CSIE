const {Menu, shell, app} = require('electron')
const os = require('os')
const selectFolder = require('./selectFolder')

module.exports = (outdatedVersion, sharedFolderClient) => {

const isMac = process.platform === 'darwin'

const template = [
  // { role: 'appMenu' }
  ...(isMac ? [{
    label: app.name,
    submenu: [
      { role: 'about' },
      { type: 'separator' },
      { role: 'services' },
      { type: 'separator' },
      { role: 'hide' },
      { role: 'hideothers' },
      { role: 'unhide' },
      { type: 'separator' },
      { role: 'quit' }
    ]
  }] : []),
  // { role: 'fileMenu' }
  {
    label: 'File',
    submenu: [
      {
        label: 'Open Folder',
        click: async () => {
          selectFolder().then((folder) => {
            sharedFolderClient(folder)
          }).catch(console.log)
        }
      },
      isMac ? { role: 'close' } : { role: 'quit' },
    ]
  },
  // { role: 'editMenu' }
  {
    label: 'Edit',
    submenu: [
      { role: 'undo' },
      { role: 'redo' },
      { type: 'separator' },
      { role: 'cut' },
      { role: 'copy' },
      { role: 'paste' },
      ...(isMac ? [
        { role: 'pasteAndMatchStyle' },
        { role: 'delete' },
        { role: 'selectAll' },
        { type: 'separator' },
        {
          label: 'Speech',
          submenu: [
            { role: 'startspeaking' },
            { role: 'stopspeaking' }
          ]
        }
      ] : [
        { role: 'delete' },
        { type: 'separator' },
        { role: 'selectAll' }
      ])
    ]
  },
  // { role: 'viewMenu' }
  {
    label: 'View',
    submenu: [
      // { role: 'reload' },
      // { role: 'forcereload' },
      { role: 'resetzoom' },
      { role: 'zoomin' },
      { role: 'zoomout' },
      { type: 'separator' },
      { role: 'togglefullscreen' }
    ]
  },
  // { role: 'windowMenu' }
  {
    label: 'Window',
    submenu: [
      { role: 'minimize' },
      { role: 'zoom' },
      ...(isMac ? [
        { type: 'separator' },
        { role: 'front' },
        { type: 'separator' },
        { role: 'window' }
      ] : [
        { role: 'close' }
      ])
    ]
  },
  {
    role: 'help',
    submenu: [
      {
        label: 'Learn More',
        click: async () => {
          shell.openExternal('https://remix-ide.readthedocs.io')
        }
      },
      {
        label: 'Medium Posts',
        click: async () => {
          shell.openExternal('https://medium.com/remix-ide')
        }
      },
      {
        label: 'Community Discussions',
        click: async () => {
          shell.openExternal('https://gitter.im/ethereum/remix')
        }
      },
      {
        label: 'Remix in StackExchange.com',
        click: async () => {
          shell.openExternal('https://ethereum.stackexchange.com/questions/tagged/remix')
        }
      },
      {
        label: 'Check Releases',
        click: async () => {
          shell.openExternal('https://github.com/ethereum/remix-desktop/releases')
        }
      },
      {
        label: 'Report Bugs / Issues',
        click: async () => {
          shell.openExternal('https://github.com/ethereum/remix-ide/issues')
        }
      },
      { role: 'toggledevtools' },
    ]
  }
]
if (outdatedVersion) {
  template.push({
    label: 'New Release Available',
    submenu: [
      {
        label: 'Remix Desktop release page',
        click: async () => {
          shell.openExternal('https://github.com/ethereum/remix-desktop/releases')
        }
      },
    ]
  })
}
const menu = Menu.buildFromTemplate(template)
Menu.setApplicationMenu(menu) 

}
