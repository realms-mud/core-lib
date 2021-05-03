//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include <functionlist.h>

object Strings;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    string *functions = filter(
        functionlist(this_object(), RETURN_FUNCTION_NAME),
        (: sizeof(regexp(({ $1 }), "__inline")) :));

    ignoreList += functions;
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Strings = clone_object("/secure/simulated-efuns/strings.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Strings);
}

/////////////////////////////////////////////////////////////////////////////
void CanFormatEmptyLine()
{
    ExpectEq("", Strings.format("", 10));
}

/////////////////////////////////////////////////////////////////////////////
void CanFormatASimpleLine()
{
    ExpectEq("This is\nthe land\nloving\nmother\npigeon of\nall\nstrings.\n", 
        Strings.format("This is the land loving mother pigeon of all strings.", 10));
}

/////////////////////////////////////////////////////////////////////////////
void CanFormatAStringWithANSIColorCharacters()
{
    ExpectEq("This \x1b[0;31mis\x1b[0m\n\x1b[0;32mthe \x1b[0;33mland"
        "\n\x1b[0;38;2;150;230;190mloving\x1b[0m\nmother\n"
        "\x1b[0;38;2;110;230;190mpigeon of\n\x1b[0m all\nstrings.\n",
        Strings.format("This \x1b[0;31mis\x1b[0m \x1b[0;32mthe \x1b[0;33mland "
            "\x1b[0;38;2;150;230;190mloving\x1b[0m mother "
            "\x1b[0;38;2;110;230;190mpigeon of\x1b[0m all strings.", 10));
}
