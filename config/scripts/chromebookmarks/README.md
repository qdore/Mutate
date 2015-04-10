## Chrome Bookmarks plugin

#### Usage
    b <query>

#### Configuration (config.ini)


Listing of the possible configuration parameters:

---


    bookmarksPath:


    his is the path of the google-chrome bookmark file
    usually it should be in '~/.config/google-chrome/Default/Bookmarks'
    empty string makes script look for Bookmark file automatically
    allowed values = <string>
    default = automatic search

---

    OnlyBookmarksBar:
    makes the script search only in the bookmarks bar
    allowed values = [true|false]
    default = true

---

    SpaceMeaning:
    this parameter give a meaning to the space character while searching:
    AND means that the bookmark result must have all the words you type in mutate
    OR means that the bookmark result must have at least 1 of the words
    allowed values = ['AND'|'OR']
    default AND
