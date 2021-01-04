//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef itemFormatters_h
#define itemFormatters_h

/////////////////////////////////////////////////////////////////////////////
private nosave mapping decorators = ([
    "dividers":([
        "any": ([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;124m",
            "24-bit": "\x1b[0;38;2;160;10;0m"
        ]),
    ]),
    "player guilds":([
        "any":([
            "grayscale": "\x1b[0;38;5;252m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
    ]),
    "wizard levels":([
        "apprentice":([
            "grayscale": "\x1b[0;38;5;234m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;133m",
            "24-bit": "\x1b[0;38;2;100;200;100m"
        ]),
        "wizard":([
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;144m",
            "24-bit": "\x1b[0;38;2;200;200;200m"
        ]),
        "creator":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;212m",
            "24-bit": "\x1b[0;38;2;100;200;10m"
        ]),
        "highwizard":([
            "grayscale": "\x1b[0;38;5;242m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;202m",
            "24-bit": "\x1b[0;38;2;10;200;100m"
        ]),
        "senior":([
            "grayscale": "\x1b[0;38;5;244m",
            "3-bit": "\x1b[0;33;1m",
            "8-bit": "\x1b[0;38;5;199m",
            "24-bit": "\x1b[0;38;2;100;20;100m"
        ]),
        "admin":([
            "grayscale": "\x1b[0;38;5;246m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;178m",
            "24-bit": "\x1b[0;38;2;200;20;100m"
        ]),
        "elder":([
            "grayscale": "\x1b[0;38;5;248m",
            "3-bit": "\x1b[0;36;1m",
            "8-bit": "\x1b[0;38;5;220m",
            "24-bit": "\x1b[0;38;2;100;20;200m"
        ]),
        "sage":([
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;35;1m",
            "8-bit": "\x1b[0;38;5;140m",
            "24-bit": "\x1b[0;38;2;100;20;10m"
        ]),
        "archwizard":([
            "grayscale": "\x1b[0;38;5;252m",
            "3-bit": "\x1b[0;34m",
            "8-bit": "\x1b[0;38;5;240m",
            "24-bit": "\x1b[0;38;2;10;20;100m"
        ]),
        "demigod":([
            "grayscale": "\x1b[0;38;5;2253m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;90m",
            "24-bit": "\x1b[0;38;2;80;80;80m"
        ]),
        "god":([
            "grayscale": "\x1b[0;38;5;254m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;111m",
            "24-bit": "\x1b[0;38;2;130;130;130m"
        ]),
        "owner":([
            "grayscale": "\x1b[0;38;5;255;1m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;20m",
            "24-bit": "\x1b[0;38;2;50;50;150m"
        ]),
    ]),
    "wizard commands":([
        "message":([
            "grayscale": "\x1b[0;38;5;253m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;178m",
            "24-bit": "\x1b[0;38;2;200;20;100m"
        ]),
        "error message":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
        "error details":([
            "grayscale": "\x1b[0;38;5;238m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;0;0;1m"
        ]),
        "environment changed":([
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;212;1m",
            "24-bit": "\x1b[0;38;2;100;200;10;1m"
        ]),
        "no access":([
            "grayscale": "\x1b[0;38;5;236m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
        "compiled":([
            "grayscale": "\x1b[0;38;5;246m",
            "3-bit": "\x1b[0;33;1m",
            "8-bit": "\x1b[0;38;5;190;1m",
            "24-bit": "\x1b[0;38;2;200;200;0;1m"
        ]),
        "normal":([
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "directory":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;20;1m",
            "24-bit": "\x1b[0;38;2;0;0;220;1m"
        ]),
        "roles":([
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
        "permissions":([
            "grayscale": "\x1b[0;38;5;248m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;212m",
            "24-bit": "\x1b[0;38;2;100;200;10m"
        ]),
        "file size":([
            "grayscale": "\x1b[0;38;5;242m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;15m",
            "24-bit": "\x1b[0;38;2;255;255;255m"
        ]),
    ]),
    "show":([
        "environment":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;2m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
        "text":([
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;92m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "own objects":([
            "grayscale": "\x1b[0;38;5;254m",
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
        "guild objects":([
            "grayscale": "\x1b[0;38;5;244m",
            "3-bit": "\x1b[0;35;1m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
        "other objects":([
            "grayscale": "\x1b[0;38;5;255m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
    ]),
    "people":([
        "ip address":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
        "name":([
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;2m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
        "level":([
            "grayscale": "\x1b[0;38;5;253m",
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
        "status":([
            "grayscale": "\x1b[0;38;5;248m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
        "location":([
            "grayscale": "\x1b[0;38;5;244m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
    ]),
    "channel":([
        "header":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;112m",
            "24-bit": "\x1b[0;38;2;190;90;190m"
        ]),
        "body":([
            "grayscale": "\x1b[0;38;5;252m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;200;230;10m"
        ]),
    ]),
    "tell":([
        "message":([
            "grayscale": "\x1b[0;38;5;252m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;112m",
            "24-bit": "\x1b[0;38;2;190;90;190m"
        ]),
        "block":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;20m",
            "24-bit": "\x1b[0;38;2;50;50;150m"
        ]),
        "busy":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;20m",
            "24-bit": "\x1b[0;38;2;50;50;150m"
        ]),
    ]),
    "soul":([
        "message":([
            "grayscale": "\x1b[0;38;5;252m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;92m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "block":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;20m",
            "24-bit": "\x1b[0;38;2;50;50;150m"
        ]),
    ]),
    "help":([
        "text":([
            "grayscale": "\x1b[0;38;5;255m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "url":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;93m",
            "24-bit": "\x1b[0;38;2;180;180;220m"
        ]),
        "heading":([
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;36;1m",
            "8-bit": "\x1b[0;38;5;15;1m",
            "24-bit": "\x1b[0;38;2;255;255;255;1m"
        ]),
        "parameter":([
            "grayscale": "\x1b[0;38;5;255;1m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;202m",
            "24-bit": "\x1b[0;38;2;10;200;100m"
        ]),
        "page":([
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;35;1m",
            "8-bit": "\x1b[0;38;5;31;1m",
            "24-bit": "\x1b[0;38;2;80;155;175;1m"
        ]), 
        "wildcard":([
            "grayscale": "\x1b[0;38;5;246m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;20m",
            "24-bit": "\x1b[0;38;2;50;50;150m"
        ]),
        "issue":([
            "grayscale": "\x1b[0;38;5;252m",
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;149;1m",
            "24-bit": "\x1b[0;38;2;210;220;40;1m"  
        ]), 
    ]),
    "shout":([
        "message":([
            "grayscale": "\x1b[0;38;5;252m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;112m",
            "24-bit": "\x1b[0;38;2;190;90;190m"
        ]),
        "help display":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;2m",
            "24-bit": "\x1b[0;38;2;170;180;110m"
        ]),
        "system message":([
            "grayscale": "\x1b[0;38;5;248m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;250;0;0;1m"
        ]),
    ]),
    "say":([
        "message":([
            "grayscale": "\x1b[0;38;5;253m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;15m",
            "24-bit": "\x1b[0;38;2;255;255;255m"
        ]),
        "help display":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;2m",
            "24-bit": "\x1b[0;38;2;170;180;110m"
        ]),
    ]),
    "tutorial": ([
        "rune wall":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;20m",
            "24-bit": "\x1b[0;38;2;0;5;170m"
        ]),
    ]),
    "selector":([
        "number":([
            "grayscale": "\x1b[0;38;5;237;1m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;220;40;0;1m"
        ]),
        "title":([
            "grayscale": "\x1b[0;38;5;255m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "menu name":([
            "grayscale": "\x1b[0;38;5;247m",
            "3-bit": "\x1b[0;37;1m",
            "8-bit": "\x1b[0;38;5;15;1m",
            "24-bit": "\x1b[0;38;2;255;255;255;1m"
        ]),
        "choice enabled":([
            "grayscale": "\x1b[0;38;5;242m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;2m",
            "24-bit": "\x1b[0;38;2;170;180;110m"
        ]),
        "choice disabled":([
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
        "prerequisites":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;20m",
            "24-bit": "\x1b[0;38;2;0;5;195m"
        ]),
        "instructions":([
            "grayscale": "\x1b[0;38;5;250;1m",
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;2;1m",
            "24-bit": "\x1b[0;38;2;160;220;60;1m"
        ]),
        "details":([
            "grayscale": "\x1b[0;38;5;253m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;144m",
            "24-bit": "\x1b[0;38;2;100;180;150m"  
        ]),
        "data" : ([
            "grayscale": "\x1b[0;38;5;249m",
            "3-bit":"\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;144m",
            "24-bit": "\x1b[0;38;2;180;180;100m"
        ]),
        "description":([
            "grayscale": "\x1b[0;38;5;253m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;116m",
            "24-bit": "\x1b[0;38;2;140;180;190m"
        ]),
        "action":([
            "grayscale": "\x1b[0;38;5;244m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;117m",
            "24-bit": "\x1b[0;38;2;140;180;190m"
        ]),
        "selected":([
            "grayscale": "\x1b[0;38;5;248m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;20;1m",
            "24-bit": "\x1b[0;38;2;0;0;220;1m"
        ]),
        "blocked":([
            "grayscale": "\x1b[0;38;5;242m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;220;40;0;1m"
        ]),
        "information":([
            "grayscale": "\x1b[0;38;5;250;1m",
            "3-bit": "\x1b[0;35;1m",
            "8-bit": "\x1b[0;38;5;20;1m",
            "24-bit": "\x1b[0;38;2;0;5;170;1m"
        ]),
        "failure":([
            "grayscale": "\x1b[0;38;5;236m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;124m",
            "24-bit": "\x1b[0;38;2;140;0;0m"
        ]),
        "note":([
            "grayscale": "\x1b[0;38;5;249m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;31m",
            "24-bit": "\x1b[0;38;2;80;155;175m"
        ]),
        "warning":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;238;1m",
            "24-bit": "\x1b[0;38;2;70;60;60;1m"
        ]),
        "decorator":([
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
    ]),
    "equipment":([
        "normal quality":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;37;1m",
            "8-bit": "\x1b[0;38;5;231;1m",
            "24-bit": "\x1b[0;38;2;255;255;255;1m"
        ]),
        "well-crafted":([
            "grayscale": "\x1b[0;38;5;244m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;144m",
            "24-bit": "\x1b[0;38;2;60;180;160m"  
        ]),   
        "masterwork":([
            "grayscale": "\x1b[0;38;5;248m",
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;149;1m",
            "24-bit": "\x1b[0;38;2;210;220;40;1m"  
        ]),   
        "enchanted":([
            "grayscale": "\x1b[0;38;5;251m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;31m",
            "24-bit": "\x1b[0;38;2;50;75;195m"
        ]),   
        "powerful enchantment":([
            "grayscale": "\x1b[0;38;5;253m",
            "3-bit": "\x1b[0;35;1m",
            "8-bit": "\x1b[0;38;5;32;1m",
            "24-bit": "\x1b[0;38;2;60;75;215;1m"
        ]), 
        "unidentified": ([
            "grayscale": "\x1b[0;38;5;255m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "field": ([
            "grayscale": "\x1b[0;38;5;247m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "value": ([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "nothing":([
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;238;1m",
            "24-bit": "\x1b[0;38;2;70;60;60;1m"
        ]),
        "cursed":([
            "grayscale": "\x1b[0;38;5;236m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;238;1m",
            "24-bit": "\x1b[0;38;2;70;60;60;1m"
        ]),
        "bonus":([
            "grayscale": "\x1b[0;38;5;248m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
        "error message":([
            "grayscale": "\x1b[0;38;5;238m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
    ]),
    "shop":([
        "unidentified":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;238;1m",
            "24-bit": "\x1b[0;38;2;70;60;60;1m"
        ]),
        "message":([
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;144m",
            "24-bit": "\x1b[0;38;2;100;180;150m"  
        ]),  
        "sell all":([
            "grayscale": "\x1b[0;38;5;239m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;238;1m",
            "24-bit": "\x1b[0;38;2;70;60;60;1m"
        ]),
        "accounting":([
            "grayscale": "\x1b[0;38;5;244m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;231m",
            "24-bit": "\x1b[0;38;2;255;255;255m"
        ]),
        "field": ([
            "grayscale": "\x1b[0;38;5;247m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "value": ([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
         "cost":([
            "grayscale": "\x1b[0;38;5;246m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;2m",
            "24-bit": "\x1b[0;38;2;170;180;110m"
        ]),
    ]),
    "environment":([
        "action":([
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;144m",
            "24-bit": "\x1b[0;38;2;100;180;150m"  
        ]),
        "description":([
            "grayscale": "\x1b[0;38;5;248m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;186m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "exits":([
            "grayscale": "\x1b[0;38;5;242m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;238;1m",
            "24-bit": "\x1b[0;38;2;60;60;70;1m"
        ]),
        "too dark":([
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
        "inventory": ([
            "grayscale": "\x1b[0;38;5;254m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "infravision": ([
            "grayscale": "\x1b[0;38;5;241m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;166m",
            "24-bit": "\x1b[0;38;2;215;95;0m"
        ]),
        "dawn": ([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;166m",
            "24-bit": "\x1b[0;38;2;215;95;0m"
        ]),
        "dusk": ([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;166m",
            "24-bit": "\x1b[0;38;2;215;105;0m"
        ]),
        "morning": ([
            "grayscale": "\x1b[0;38;5;248m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;184m",
            "24-bit": "\x1b[0;38;2;230;215;0m"
        ]),
        "noon": ([
            "grayscale": "\x1b[0;38;5;253m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;226m",
            "24-bit": "\x1b[0;38;2;255;255;0m"
        ]),
        "afternoon": ([
            "grayscale": "\x1b[0;38;5;248m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;230;255;0m"
        ]),
        "evening": ([
            "grayscale": "\x1b[0;38;5;238m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;184m",
            "24-bit": "\x1b[0;38;2;230;215;0m"
        ]),
        "midnight": ([
            "grayscale": "\x1b[0;38;5;234m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;56m",
            "24-bit": "\x1b[0;38;2;85;0;215m"
        ]),
        "night": ([
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;57m",
            "24-bit": "\x1b[0;38;2;95;0;255m"
        ]),
        "late night": ([
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;57m",
            "24-bit": "\x1b[0;38;2;95;0;255m"
        ]),
    ]),
    "score":([
        "character":([
            "grayscale": "\x1b[0;38;5;255m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;144m",
            "24-bit": "\x1b[0;38;2;100;180;150m"  
        ]),
        "value":([
            "grayscale": "\x1b[0;38;5;248m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;2m",
            "24-bit": "\x1b[0;38;2;170;180;110m"
        ]),
        "content": ([
            "grayscale": "\x1b[0;38;5;253m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "weapon":([
            "grayscale": "\x1b[0;38;5;246m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "information":([
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "bar":([
            "grayscale": "\x1b[0;38;5;245m",
            "3-bit": "\x1b[0;35;1m",
            "8-bit": "\x1b[0;38;5;238;1m",
            "24-bit": "\x1b[0;38;2;60;60;70;1m"
        ]),
        "empty bar":([
            "grayscale": "\x1b[0;38;5;236m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
        "level up":([
            "grayscale": "\x1b[0;38;5;253;1m",
            "3-bit": "\x1b[0;33;1m",
            "8-bit": "\x1b[0;38;5;190;1m",
            "24-bit": "\x1b[0;38;2;200;200;0;1m"
        ]),
        "attribute":([
            "grayscale": "\x1b[0;38;5;249m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;2m",
            "24-bit": "\x1b[0;38;2;170;180;110m"
        ]),
        "attribute bonus":([
            "grayscale": "\x1b[0;38;5;245;1m",
            "3-bit": "\x1b[0;33;1m",
            "8-bit": "\x1b[0;38;5;190;1m",
            "24-bit": "\x1b[0;38;2;200;200;0;1m"
        ]),
        "attribute penalty":([
            "grayscale": "\x1b[0;38;5;235;1m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;0;0;1m"
        ]),
        "positive modifier":([
            "grayscale": "\x1b[0;38;5;245m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;20;1m",
            "24-bit": "\x1b[0;38;2;0;0;220;1m"
        ]),
        "negative modifier":([
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
        "statistics level":([
            "grayscale": "\x1b[0;38;5;247m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;238m",
            "24-bit": "\x1b[0;38;2;60;60;70m"
        ]),
         "statistics info":([
            "grayscale": "\x1b[0;38;5;251m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;0;0;1m"
        ]),
   ]),
   "long description":([
        "name":([
            "grayscale": "\x1b[0;38;5;255m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "gender":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;238m",
            "24-bit": "\x1b[0;38;2;90;60;160m"
        ]),
        "race":([
            "grayscale": "\x1b[0;38;5;244m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;2m",
            "24-bit": "\x1b[0;38;2;170;180;110m"
        ]),
        "description": ([
            "grayscale": "\x1b[0;38;5;252m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "carry header": ([
            "grayscale": "\x1b[0;38;5;245m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "health":([
            "grayscale": "\x1b[0;38;5;247m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;0;0;1m"
        ]),
    ]),
    "research":([
        "bonus text":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "bonus modifier":([
            "grayscale": "\x1b[0;38;5;246m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;20;1m",
            "24-bit": "\x1b[0;38;2;10;20;100;1m"
        ]),
        "penalty modifier":([
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
        "apply modifier":([
            "grayscale": "\x1b[0;38;5;245m",
            "3-bit": "\x1b[0;35;1m",
            "8-bit": "\x1b[0;38;5;31;1m",
            "24-bit": "\x1b[0;38;2;80;155;175;1m"
        ]), 
        "time left":([
            "grayscale": "\x1b[0;38;5;238m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;0;0;1m"
        ]),
        "missing prerequisites":([
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
        "prerequisite":([
            "grayscale": "\x1b[0;38;5;236m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;31m",
            "24-bit": "\x1b[0;38;2;80;125;185m"
        ]), 
        "equivalent":([
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;34m",
            "8-bit": "\x1b[0;38;5;19m",
            "24-bit": "\x1b[0;38;2;0;5;160m"
        ]),
        "known":([
            "grayscale": "\x1b[0;38;5;248m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;20;1m",
            "24-bit": "\x1b[0;38;2;0;0;220;1m"
        ]),
        "limiter passed":([
            "grayscale": "\x1b[0;38;5;249m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;20;1m",
            "24-bit": "\x1b[0;38;2;0;0;220;1m"
        ]),
        "limiter failed":([
            "grayscale": "\x1b[0;38;5;236m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;0;0;1m"
        ]),
        "in progress":([
            "grayscale": "\x1b[0;38;5;245m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;31m",
            "24-bit": "\x1b[0;38;2;80;155;175m"
        ]), 
        "available tree":([
            "grayscale": "\x1b[0;38;5;252m",
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;149;1m",
            "24-bit": "\x1b[0;38;2;100;220;150;1m"  
        ]),  
        "field header": ([
            "grayscale": "\x1b[0;38;5;244m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "field data":([
            "grayscale": "\x1b[0;38;5;251m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "tree indentation":([
            "grayscale": "\x1b[0;38;5;234m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
        "command": ([
            "grayscale": "\x1b[0;38;5;254m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "target": ([
            "grayscale": "\x1b[0;38;5;243m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "formula":([
            "grayscale": "\x1b[0;38;5;248m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;20;1m",
            "24-bit": "\x1b[0;38;2;10;20;100;1m"
        ]),
        "formula type":([
            "grayscale": "\x1b[0;38;5;241m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;0;0;1m"
        ]),
        "failure message":([
            "grayscale": "\x1b[0;38;5;236m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;0;0;1m"
        ]),
    ]),
    "races":([
        "information":([
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;2m",
            "24-bit": "\x1b[0;38;2;170;180;110m"
        ]),
        "bonus modifier":([
            "grayscale": "\x1b[0;38;5;243m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;20;1m",
            "24-bit": "\x1b[0;38;2;10;20;100;1m"
        ]),
        "penalty modifier":([
            "grayscale": "\x1b[0;38;5;236m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
    ]),
    "skills":([
        "information":([
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;2m",
            "24-bit": "\x1b[0;38;2;170;180;110m"
        ]),
        "modifier":([
            "grayscale": "\x1b[0;38;5;243m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;20;1m",
            "24-bit": "\x1b[0;38;2;10;20;100;1m"
        ]),
        "penalty":([
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;0;0;1m"
        ]),
        "skill header": ([
            "grayscale": "\x1b[0;38;5;247m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "skill value": ([
            "grayscale": "\x1b[0;38;5;244m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "points remaining":([
            "grayscale": "\x1b[0;38;5;253m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
    ]),
    "traits":([
        "field header": ([
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "field data":([
            "grayscale": "\x1b[0;38;5;245m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "negative trait":([
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;0;0;1m"
        ]),
        "bonus modifier":([
            "grayscale": "\x1b[0;38;5;244m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;20;1m",
            "24-bit": "\x1b[0;38;2;10;20;100;1m"
        ]),
        "penalty modifier":([
            "grayscale": "\x1b[0;38;5;236m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
        "persisted trait":([
            "grayscale": "\x1b[0;38;5;249m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;25;1m",
            "24-bit": "\x1b[0;38;2;10;80;160;1m"
        ]),
        "sustained trait":([
            "grayscale": "\x1b[0;38;5;251m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;31m",
            "24-bit": "\x1b[0;38;2;80;155;175m"
        ]), 
        "has research":([
            "grayscale": "\x1b[0;38;5;246m",
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;212m",
            "24-bit": "\x1b[0;38;2;100;200;10m"
        ]),
        "enhancement":([
            "grayscale": "\x1b[0;38;5;244m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "personality trait":([
            "grayscale": "\x1b[0;38;5;251m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]), 
    ]),
    "quests":([
        "description": ([
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "failure":([
            "grayscale": "\x1b[0;38;5;237;1m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;0;0;1m"
        ]),
        "success":([
            "grayscale": "\x1b[0;38;5;248;1m",
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;212m",
            "24-bit": "\x1b[0;38;2;100;200;10m"
        ]),
        "heading" : ([
            "grayscale": "\x1b[0;38;5;248m",
            "3-bit":"\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;144m",
            "24-bit": "\x1b[0;38;2;180;180;100m"
        ]),
        "data" : ([
            "grayscale": "\x1b[0;38;5;245m",
            "3-bit":"\x1b[0;33;1m",
            "8-bit": "\x1b[0;38;5;144;1m",
            "24-bit": "\x1b[0;38;2;180;180;100;1m"
        ]),
        "active quest":([
            "grayscale": "\x1b[0;38;5;253m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;20m",
            "24-bit": "\x1b[0;38;2;0;5;170m"
        ]),
    ]),
    "conversation":([
        "description": ([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "speech":([
            "grayscale": "\x1b[0;38;5;255m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "response":([
            "grayscale": "\x1b[0;38;5;255;1m",
            "3-bit": "\x1b[0;33;1m",
            "8-bit": "\x1b[0;38;5;190;1m",
            "24-bit": "\x1b[0;38;2;200;200;0;1m"
        ]),
        "already spoken":([
            "grayscale": "\x1b[0;38;5;245m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;148m",
            "24-bit": "\x1b[0;38;2;150;150;0m"
        ]),
        "condition":([
            "grayscale": "\x1b[0;38;5;246m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;20;1m",
            "24-bit": "\x1b[0;38;2;60;20;190;1m"
        ]),
        "action":([
            "grayscale": "\x1b[0;38;5;239m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;0;0;1m"
        ]),
        "highlight":([
            "grayscale": "\x1b[0;38;5;247m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;31m",
            "24-bit": "\x1b[0;38;2;80;155;175m"
        ]), 
        "disabled": ([
            "grayscale": "\x1b[0;38;5;236m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;124m",
            "24-bit": "\x1b[0;38;2;100;10;0m"
        ]),
        "effect":([
            "grayscale": "\x1b[0;38;5;251m",
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;190;1m",
            "24-bit": "\x1b[0;38;2;220;200;0;1m"
        ]),
    ]),
    "grid":([
        "display":([
            "grayscale": "\x1b[0;38;5;238m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
    ]),
    "combat":([
        "death":([
            "grayscale": "\x1b[0;38;5;236;1m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;0;0;1m"
        ]),
        "flee":([
            "grayscale": "\x1b[0;38;5;251m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "damage":([
            "grayscale": "\x1b[0;38;5;238m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;240;0;0m"
        ]),
        "light hit": ([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;26m",
            "24-bit": "\x1b[0;38;2;150;150;200m"
        ]),
        "hit": ([
            "grayscale": "\x1b[0;38;5;243m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;25m",
            "24-bit": "\x1b[0;38;2;140;140;170m"
        ]),
        "heavy hit": ([
            "grayscale": "\x1b[0;38;5;245m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;24m",
            "24-bit": "\x1b[0;38;2;120;120;160m"
        ]),
        "extreme hit": ([
            "grayscale": "\x1b[0;38;5;249;1m",
            "3-bit": "\x1b[0;36;1m",
            "8-bit": "\x1b[0;38;5;31;1m",
            "24-bit": "\x1b[0;38;2;130;130;170;1m"
        ]),
        "miss":([
            "grayscale": "\x1b[0;38;5;239m",
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;180m",
            "24-bit": "\x1b[0;38;2;140;170;140m"
        ]),
    ]),
    "combat assessment": ([
        "very easy":([
            "grayscale": "\x1b[0;38;5;238m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;10m",
            "24-bit": "\x1b[0;38;2;0;255;0m"
        ]),
        "easy":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;40m",
            "24-bit": "\x1b[0;38;2;0;180;0m"
        ]),
        "somewhat easy":([
            "grayscale": "\x1b[0;38;5;242m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;34m",
            "24-bit": "\x1b[0;38;2;100;200;100m"
        ]),
        "even":([
            "grayscale": "\x1b[0;38;5;244m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;11m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "somewhat challenging":([
            "grayscale": "\x1b[0;38;5;246m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;214m",
            "24-bit": "\x1b[0;38;2;200;150;0m"
        ]),
        "challenging":([
            "grayscale": "\x1b[0;38;5;248m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;166m",
            "24-bit": "\x1b[0;38;2;255;180;0m"
        ]),
        "suicidal":([
            "grayscale": "\x1b[0;38;5;252m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
        "override":([
            "grayscale": "\x1b[0;38;5;255m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;44m",
            "24-bit": "\x1b[0;38;2;0;200;200m"
        ]),
    ]),
    "party":([
        "active member":([
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "npc":([
            "grayscale": "\x1b[0;38;5;243m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;147m",
            "24-bit": "\x1b[0;38;2;190;200;255m"
        ]),
        "creator":([
            "grayscale": "\x1b[0;38;5;255;1m",
            "3-bit": "\x1b[0;33;1m",
            "8-bit": "\x1b[0;38;5;190;1m",
            "24-bit": "\x1b[0;38;2;200;200;0;1m"
        ]),
        "heading":([
            "grayscale": "\x1b[0;38;5;254m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;0;0;1m"
        ]),    
        "former member":([
            "grayscale": "\x1b[0;38;5;236m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),  
        "data": ([
            "grayscale": "\x1b[0;38;5;253m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
    ]),
    "tactical combat":([
        "extra message":([
            "grayscale": "\x1b[0;38;5;253m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;0;0;1m"
        ]),
        "attacker": ([
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;25m",
            "24-bit": "\x1b[0;38;2;140;140;170m"
        ]),
        "defender":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;180m",
            "24-bit": "\x1b[0;38;2;140;170;140m"
        ]),
        "summary": ([
            "grayscale": "\x1b[0;38;5;255",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
    ]),
    "map": ([
        "none": ([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;245m",
            "24-bit": "\x1b[0;38;2;138;138;138m"
        ]),
        "corridor": ([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;240m",
            "24-bit": "\x1b[0;38;2;88;88;95m"
        ]),
        "exit": ([
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;239m",
            "24-bit": "\x1b[0;38;2;78;78;78m"
        ]),
        "room": ([
            "grayscale": "\x1b[0;38;5;254m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;12;1m",
            "24-bit": "\x1b[0;38;2;0;0;255;1m"
        ]),
        "shop": ([
            "grayscale": "\x1b[0;38;5;255m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;0;0;1m"
        ]),
        "user location": ([
            "grayscale": "\x1b[0;38;5;247m",
            "3-bit": "\x1b[0;41;33m",
            "8-bit": "\x1b[0;48;5;52;38;5;10m",
            "24-bit": "\x1b[0;48;2;90;0;0;38;2;0;255;0m",
        ]),
        "training ground": ([
            "grayscale": "\x1b[0;38;5;254m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "plants": ([
            "grayscale": "\x1b[0;38;5;243m",
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;35m",
            "24-bit": "\x1b[0;38;2;0;175;90m",
        ]),
        "reverse": ([
            "grayscale": "\x1b[0;48;5;240m",
            "3-bit": "\x1b[0;41m",
            "8-bit": "\x1b[0;48;5;52m",
            "24-bit": "\x1b[0;48;2;90;0;0m",
        ]),
        "divider": ([
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
        "error": ([
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
        "wood building": ([
            "grayscale": "\x1b[0;38;5;241m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "stone building": ([
            "grayscale": "\x1b[0;38;5;249m",
            "3-bit": "\x1b[0;36;1m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;180m"
        ]),
    ]),
    "player domains":([
        "heading": ([
            "grayscale": "\x1b[0;38;5;254m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "worker": ([
            "grayscale": "\x1b[0;38;5;251m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "low end worker": ([
            "grayscale": "\x1b[0;38;5;239m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;0;0;1m"
        ]),
        "average worker": ([
            "grayscale": "\x1b[0;38;5;243m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "elite worker": ([
            "grayscale": "\x1b[0;38;5;247m",
            "3-bit": "\x1b[0;33;1m",
            "8-bit": "\x1b[0;38;5;190;1m",
            "24-bit": "\x1b[0;38;2;200;200;0;1m"
        ]),
        "total": ([
            "grayscale": "\x1b[0;38;5;254m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;212m",
            "24-bit": "\x1b[0;38;2;100;200;10m"
        ]),
        "incomplete": ([
            "grayscale": "\x1b[0;38;5;238m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;0;0;1m"
        ]),
        "value": ([
            "grayscale": "\x1b[0;38;5;249m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "selection needed": ([
            "grayscale": "\x1b[0;38;5;242m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;24m",
            "24-bit": "\x1b[0;38;2;140;140;180m"
        ]),
        "not selected yet": ([
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
        "selected":([
            "grayscale": "\x1b[0;38;5;247m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;25;1m",
            "24-bit": "\x1b[0;38;2;10;80;160;1m"
        ]),
        "busy":([
            "grayscale": "\x1b[0;38;5;255m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
        "is remote": ([
            "grayscale": "\x1b[0;38;5;243m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;60;0;1m"
        ]),
        "positive value":([
            "grayscale": "\x1b[0;38;5;245m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;25;1m",
            "24-bit": "\x1b[0;38;2;10;80;160;1m"
        ]),
        "negative value":([
            "grayscale": "\x1b[0;38;5;236m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
    ]),
    "harvestable resources":([
        "missing prerequisites":([
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
        "field header": ([
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "field data":([
            "grayscale": "\x1b[0;38;5;253m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "quantity left":([
            "grayscale": "\x1b[0;38;5;247m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;20;1m",
            "24-bit": "\x1b[0;38;2;10;20;100;1m"
        ]),
        "quantity zero":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;0;0;1m"
        ]),
    ]),
    "element bonuses":([
        "missing prerequisites":([
            "grayscale": "\x1b[0;38;5;237m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
        "field header": ([
            "grayscale": "\x1b[0;38;5;250m",
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "field data":([
            "grayscale": "\x1b[0;38;5;253m",
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "bonus":([
            "grayscale": "\x1b[0;38;5;247m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;20;1m",
            "24-bit": "\x1b[0;38;2;10;20;100;1m"
        ]),
        "penalty":([
            "grayscale": "\x1b[0;38;5;240m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;200;0;0;1m"
        ]),
    ]),

]);

#endif
