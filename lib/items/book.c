//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/item.c";

private mapping *BookChapters = ({});

/////////////////////////////////////////////////////////////////////////////
public int addChapter(string chapterTitle, string text)
{
    if (chapterTitle && stringp(chapterTitle) && text && stringp(text))
    {
        BookChapters += ({ (["title": chapterTitle, "text": text]) });
        return 1;
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public int numChapters()
{
    return sizeof(BookChapters);
}

/////////////////////////////////////////////////////////////////////////////
public string readChapter(int chapter)
{
    if (chapter > 0 && chapter <= sizeof(BookChapters))
    {
        mapping chapterData = BookChapters[chapter - 1];

        return sprintf("\n  %s\n\n%s\n", chapterData["title"],
            format(chapterData["text"], 78));
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mixed query(string element)
{
    mixed ret = 0;
    switch(element)
    {
        case "type":
        {
            ret = "book";
            break;
        }
        case "title":
        {
            ret = member(itemData, "title") ? itemData["title"] : 0;
            break;
        }
        case "chapters":
        {
            ret = BookChapters + ({});
            break;
        }
        case "low light description":
        {
            ret = "The silhouette of a small, rectangular object";
            break;
        }
        case "dim light description":
        {
            ret = "Something that appears to be a book";
            break;
        }
        default:
        {
            ret = item::query(element);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public varargs int set(string element, mixed data)
{
    if (element == "title")
    {
        if (!data || !stringp(data))
        {
            raise_error("Book: The passed 'title' data "
                "must be a string.\n");
        }
        itemData["title"] = data;
        return 1;
    }
    return item::set(element, data);
}
