pkgname=pdwm
pkgver=1.0
pkgrel=1
pkgdesc="Minimalist dynamic window manager setup"
arch=('x86_64')
url="https://github.com/purrlinux/pdwm"
license=('MIT')
depends=('xorg' 'xorg-xinit' 'feh')
makedepends=('git' 'make' 'gcc')
source=("git+https://github.com/purrlinux/pdwm.git")
sha256sums=('SKIP')

build() {
    cd "$srcdir/pdwm"

    for dir in dmenu-5.3 dwm-6.5 slock-1.5 slstatus-1.0 st-0.9.2; do
        cd "$dir"
        make
        cd ..
    done
}

package() {
    cd "$srcdir/pdwm"

    install -Dm755 dwm-6.5/dwm "$pkgdir/usr/bin/dwm"
    install -Dm755 dmenu-5.3/dmenu "$pkgdir/usr/bin/dmenu"
    install -Dm755 slock-1.5/slock "$pkgdir/usr/bin/slock"
    install -Dm755 slstatus-1.0/slstatus "$pkgdir/usr/bin/slstatus"
    install -Dm755 st-0.9.2/st "$pkgdir/usr/bin/st"

    install -Dm644 "$srcdir/pdwm/.xinitrc" "$pkgdir/etc/skel/.xinitrc"

    install -Dm644 "$srcdir/pdwm/wallpaper.png" "$pkgdir/usr/share/pdwm/wallpaper.png"
}

post_install() {
    echo "pdwm is installed! Don't forget to copy .xinitrc to the home folder:"
    echo "cp /etc/skel/.xinitrc ~/.xinitrc"
}

post_remove() {
    echo "pdwm has been removed"
}

