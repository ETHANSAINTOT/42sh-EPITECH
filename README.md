# 42sh

**42sh** est un projet académique réalisé dans le cadre de la formation EPITECH.  
L'objectif est de recréer un shell Unix fonctionnel, similaire à `tcsh`, capable d'exécuter des commandes système, de gérer des redirections, des pipes et plusieurs commandes internes (built-ins).

---

## 🚀 Objectif du Projet

Recréer un **shell Unix** comportant les fonctionnalités essentielles d'un shell comme `tcsh`, `zsh`, ou `bash`.

Fonctionnalités principales :

- Exécution de toutes les commandes système
- Implémentation de **built-ins** :
  - `env`
  - `setenv`
  - `unsetenv`
  - `cd`
  - `exit`
  - `which`
- Gestion des **pipes (`|`)**
- Gestion des **redirections (`>`, `>>`, `<`)**
- Support des **commandes enchaînées** dans un shell interactif

---

## 🛠️ Prérequis

Pour faire fonctionner le projet, vous devez disposer des outils suivants :

- Un **système Linux** ou **Windows avec WSL (Windows Subsystem for Linux)**
- `git` (optionnel sous Linux, **obligatoire sous WSL**)
- `gcc`
- `make`
- `criterion` (framework de test)

---

## 📦 Installation

Clonez le dépôt via SSH :

```bash
git clone git@github.com:ETHANSAINTOT/42sh-EPITECH.git
cd 42sh-EPITECH
make
```

Pour lancer le shell :

```bash
./42sh
```

---

## ❓ Pourquoi utiliser 42sh ?

- Le **prompt est coloré** avec un affichage élégant de l’emplacement du dossier courant.
- Le **code de retour** de la dernière commande est affiché directement, très pratique pour le debug.
- Il supporte les fonctionnalités clés que vous utilisez tous les jours :

  - Exécution de commandes système classiques
  - Redirection de sortie (`>`, `>>`)
  - Redirection d'entrée (`<`)
  - Enchaînement via des pipes (`|`)
  - Built-ins pratiques (`cd`, `env`, `setenv`, `unsetenv`, `which`, `exit`)

---

## 📄 Licence & Règlement

Ce projet a été développé **dans un cadre académique à EPITECH**.  
Il est **strictement interdit** :

- d'en tirer un quelconque **profit financier**
- de **le diffuser** ou **le présenter publiquement** sans mention explicite de l’école **EPITECH**

Merci de respecter ces conditions.

---

## 👨‍💻 Auteurs

Projet réalisé par :

- Simon Dutal
- Baptiste Jaunais
- Jassmine Rahmaoui
- Ethan Saintot

---

## 💻 Démo

```bash
~/GITHUB_PUBLIC/42sh-EPITECH > echo "Bonjour EPITECH" > hello.txt                                                                                                                    0

~/GITHUB_PUBLIC/42sh-EPITECH > cat hello.txt                                                                                                                                            0
Bonjour EPITECH

~/GITHUB_PUBLIC/42sh-EPITECH > echo "42sh est stylé" >> hello.txt                                                                                                                      0

~/GITHUB_PUBLIC/42sh-EPITECH > cat < hello.txt                                                                                                                                          0
Bonjour EPITECH
42sh est stylé

~/GITHUB_PUBLIC/42sh-EPITECH > cat hello.txt | grep stylé                                                                                                                               0
42sh est stylé

~/GITHUB_PUBLIC/42sh-EPITECH > cd lib                                                                                                                                                   0

~/GITHUB_PUBLIC/42sh-EPITECH/lib > cd ..                                                                                                                                                0

~/GITHUB_PUBLIC/42sh-EPITECH > which ls                                                                                                                                                0
/bin/ls

~/GITHUB_PUBLIC/42sh-EPITECH > exit                                                                                                                                                     0
```

---

## 📬 Contact

Pour toute question, merci de passer par les canaux officiels d’EPITECH ou de contacter les auteurs directement via GitHub.