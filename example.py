from serialToExcel import SerialToExcel

serialToExcel = SerialToExcel("COM13",115200)

columnas = ["Nro Lectura","Valor"]

serialToExcel.setColumns(["Nro Lectura","Valor"])
serialToExcel.setRecordsNumber(1000)
serialToExcel.readPort()

serialToExcel.writeFile("archivo4.xls")