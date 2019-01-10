set -e

if [ -z "$TRAVIS_TAG" ]; then
    echo "TRAVIS_TAG variable empty, will not download binaries"
    exit 0
fi

BASE_URL=https://github.com/baransu/graphql_ppx/releases/download/$TRAVIS_TAG/graphql_ppx-

mkdir -p bin

#win-x64 win-x86 - disable windows for now
for platform in linux-x64 darwin-x64; do
    (cd bin && curl -fOL $BASE_URL$platform.exe)
done
