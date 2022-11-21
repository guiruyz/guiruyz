from PyQt6.QtWidgets import QApplication, QWidget, QPushButton, QLabel
import sys 

app = QApplication(sys.argv)
windown_1 = QWidget()
windown_1.resize(800,600)
windown_1.setWindowTitle("sw-ssctc")

btn = QPushButton("Confirm", windown_1)
btn.setGeometry(100,100,150,80)
#btn.setStyleSheet()

label = QLabel("sw-ss v1.0", windown_1)
label.move(400,50)


windown_1.show()

app.exec()
