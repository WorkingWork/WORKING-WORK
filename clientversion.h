#ifndef CLIENTVERSION_H
#define CLIENTVERSION_H

//
// client versioning
//

// These need to be macros, as version.cpp's and bitcoin-qt.rc's voodoo requires it
#define CLIENT_VERSION_MAJOR       1
#define CLIENT_VERSION_MINOR       0
#define CLIENT_VERSION_REVISION    0
#define CLIENT_VERSION_BUILD       0

// Converts the parameter X to a string after macro replacement on X has been performed.
// Don't merge these into one macro!
#define STRINGIZE(X) DO_STRINGIZE(X)
#define DO_STRINGIZE(X) #X

#endif // CLIENTVERSION_H
rom os import path


WHITELIST_NUM = 5000
# In case we have bad actors.
WHITELSIT_SUBSTITUTE_NUM = 500


def get_user_keys_and_scores() -> [(str, float)]:
    """KYC-cleared users with score >= 60."""
    dir_path = path.dirname(path.realpath(__file__))

    with open(path.join(dir_path, 'applicants.csv')) as f:
        lines = f.readlines()
    ret = []
    # Skip header row.
    for line in lines[1:]:
        k, s = line.strip().split(',')
        ret.append((k, float(s)))
    return ret
