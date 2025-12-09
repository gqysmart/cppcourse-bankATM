---
marp: true
paginate: true
size: 16:9
---

# Projet ATM – Itération 7
## Programmation C++

**Application Bank ATM en C++**

LaSalle College – Décembre 2025  
**Étudiants : Qiyun Ge · YuPing Yan**

---

## Introduction du projet

Objectif du projet :

- Simuler un distributeur automatique bancaire
- Gestion de comptes utilisateurs
- Dépôt, retrait, consultation du solde
- Historique des opérations
- Sauvegarde persistante dans des fichiers

✅ Application console écrite en **C++ modulaire**

---

## Fonctionnement général

### Démarrage
- Compilation via **CMake**
- Chargement automatique des fichiers `data/`

### Menu principal
1. Login
2. Création de compte
3. Quitter

### Après authentification
- Afficher le solde
- Dépôt / Retrait
- Historique des opérations
- Déconnexion

---

## Structures et stockage

### Structure d’une opération
- Type (DEPOSIT / WITHDRAW)
- Montant
- Date et heure

### Structure d’un compte
- Mot de passe
- Solde
- Nombre d’opérations
- Historique des opérations

### Stockage
- 1 fichier par compte  
- Données sauvegardées localement  
- Lecture / écriture persistante

---

## Exemples d’utilisation

- ✅ Dépôt validé → solde mis à jour
- ❌ Retrait refusé si solde insuffisant
- ✅ Historique des opérations enregistré
- ✅ Données conservées après redémarrage

Le programme garantit :
- cohérence du solde
- traçabilité des opérations

---

## Conclusion

Ce projet démontre :

- L’utilisation correcte des **structures C++**
- Une architecture modulaire (.h / .cpp)
- La gestion d’un stockage persistant par fichiers
- Un programme console complet et fonctionnel

🎯 Pro
